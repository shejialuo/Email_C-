#include "IALoadBalancer.hpp"
#include <iterator>
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <chrono>

ImageAnalyser_LoadBalancer::ImageAnalyser_LoadBalancer(
    int serverPort): IALBServer(serverPort) {
    instancesConnected = {};
    nextInstance = -1;
}

void ImageAnalyser_LoadBalancer::connectInstance(
    ImageAnalysisInterface newInstance) {
    instancesConnected.push_back(newInstance);
}

ImageAnalysisInterface ImageAnalyser_LoadBalancer
    ::disconnectInstance() {
    ImageAnalysisInterface removedInstance = instancesConnected.back();
    instancesConnected.pop_back();
    Client newClient(removedInstance.ipAddr, 8000,8001);
    newClient.socket();
    newClient.bind();
    newClient.connect();
    string messageInfo = "disconnect";
    newClient.send(messageInfo);
    newClient.close();
    return removedInstance;
}

void ImageAnalyser_LoadBalancer::newRequest(
    string image, string messageId) {
    nextInstance =  (nextInstance + 1 ) % instancesConnected.size();
    auto pos = instancesConnected.cbegin();
    advance(pos, nextInstance);
    ImageAnalysisInterface selectedInstance = *pos;
    Client newClient(selectedInstance.ipAddr, 8000, 8001);
    newClient.socket();
    newClient.bind();
    newClient.connect();
    string combinedString = image + " " + messageId;
    newClient.send(combinedString);
    newClient.close();
}

void ImageAnalyser_LoadBalancer::runServer() {
    IALBServer.socket();
    IALBServer.bind();
    IALBServer.listen(5000);
    std::ofstream ofile;
    ofile.open("./log.txt");
    while(true) {
        IALBServer.accept();
        string messageInfo = IALBServer.recv();
        auto t = std::chrono::system_clock::now();
        std::time_t tt = std::chrono::system_clock::to_time_t(t);
        std::string stt = ctime(&tt);
        std::string logString = tt + " " + messageInfo;
        ofile << logString << std::endl;

        if(strcmp(messageInfo.c_str(), "new connect") == 0) {
            ImageAnalysisInterface newInstance {
                inet_ntoa(IALBServer.getClientAddr().sin_addr)};
            connectInstance(newInstance);
        }
        else if(strcmp(messageInfo.c_str(), "disconnect") == 0) {
            disconnectInstance();
        }
        else {
            vector<string> param;
            istringstream iss(messageInfo);
            string token;
            while(getline(iss,token,' ')) {
                param.push_back(token);
            }
            string image = param.at(0);
            string messageId = param.at(1);
            newRequest(image, messageId);
        }
    }
}