#include "SALoadBalancer.hpp"
#include <vector>
#include <iterator>
#include <iostream>
#include <sstream>
#include <fstream>
#include <chrono>

SentimentAnalyser_LoadBalancer::SentimentAnalyser_LoadBalancer(
    int serverPort): SALBServer(serverPort){
    instancesConnected = {};
    nextInstance = -1;    
}

SentimentAnalysisInterface SentimentAnalyser_LoadBalancer
    ::disconnectInstance() {
    SentimentAnalysisInterface removedInstance = instancesConnected.back();
    instancesConnected.pop_back();
    return removedInstance;
}

void SentimentAnalyser_LoadBalancer::connectInstance(
    SentimentAnalysisInterface newInstance) {
    instancesConnected.push_back(newInstance);
}

void SentimentAnalyser_LoadBalancer::newRequest(string messageBody, string ip) {
    nextInstance =  (nextInstance + 1) % instancesConnected.size();
    auto pos = instancesConnected.cbegin();
    advance(pos, nextInstance);
    SentimentAnalysisInterface selectedInstance = *pos;
    Client newClient(selectedInstance.ipAddr, 8000, 8001);
    newClient.socket();
    newClient.bind();
    newClient.connect();
    string combined = messageBody + ip;
    newClient.send(combined);
    newClient.close();
}

void SentimentAnalyser_LoadBalancer::runServer() {
    SALBServer.socket();
    SALBServer.bind();
    SALBServer.listen(5000);
    std::ofstream ofile;
    ofile.open("./log.txt");
    while(true) {
        SALBServer.accept();
        string ip = inet_ntoa(SALBServer.getClientAddr().sin_addr);
        string messageInfo = SALBServer.recv();
        auto t = std::chrono::system_clock::now();
        std::time_t tt = std::chrono::system_clock::to_time_t(t);
        std::string stt = ctime(&tt);
        std::string logString = tt + " " + messageInfo;
        ofile << logString << std::endl;
        if(strcmp(messageInfo.c_str(), "new connect") == 0) {
            SentimentAnalysisInterface newInstance {
                inet_ntoa(SALBServer.getClientAddr().sin_addr)};
            connectInstance(newInstance);
        }
        else if(strcmp(messageInfo.c_str(), "disconnect") == 0) {
            disconnectInstance();
        }
        else {
            newRequest(messageInfo, ip);
        }
    }
}