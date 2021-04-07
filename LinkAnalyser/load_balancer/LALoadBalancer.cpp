#include "LALoadBalancer.hpp"
#include <iterator>
#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
#include <sstream>

LinkAnalyser_LoadBalancer::LinkAnalyser_LoadBalancer(
    int serverPort): LALBServer(serverPort) {
    instancesConnected = {};
    nextInstance = -1;
}

void LinkAnalyser_LoadBalancer::connectInstance(
    LinkAnalysisInterface newInstance) {
    instancesConnected.push_back(newInstance);
}

LinkAnalysisInterface LinkAnalyser_LoadBalancer
    ::disconnectInstance() {
    LinkAnalysisInterface removedInstance = instancesConnected.back();
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

void LinkAnalyser_LoadBalancer::newRequest(
    string links, string messageId) {
    nextInstance =  (nextInstance + 1 ) % instancesConnected.size();
    auto pos = instancesConnected.cbegin();
    advance(pos, nextInstance);
    LinkAnalysisInterface selectedInstance = *pos;
    Client newClient(selectedInstance.ipAddr, 8000, 8001);
    newClient.socket();
    newClient.bind();
    newClient.connect();
    string combinedString = links + " " + messageId;
    newClient.send(combinedString);
    newClient.close();
}

void LinkAnalyser_LoadBalancer::runServer() {
    LALBServer.socket();
    LALBServer.bind();
    LALBServer.listen(5000);
    std::ofstream ofile;
    ofile.open("./log.txt");
    while(true) {
        LALBServer.accept();
        string messageInfo = LALBServer.recv();
        auto t = std::chrono::system_clock::now();
        std::time_t tt = std::chrono::system_clock::to_time_t(t);
        std::string stt = ctime(&tt);
        std::string logString = tt + " " + messageInfo;
        ofile << logString << std::endl;
        
        if(strcmp(messageInfo.c_str(), "new connect") == 0) {
            LinkAnalysisInterface newInstance {
                inet_ntoa(LALBServer.getClientAddr().sin_addr)};
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
            string links = param.at(0);
            string messageId = param.at(1);
            newRequest(links, messageId);
        }
    }
}