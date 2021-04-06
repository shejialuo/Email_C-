#include "MPLoadBalancer.hpp"
#include <iterator>
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <chrono>

MessageParser_LoadBalancer::MessageParser_LoadBalancer(
    int serverPort): MPLBServer(serverPort) {
    instancesConnected = {};
    nextInstance = -1;
}

void MessageParser_LoadBalancer::connectInstance(
    MessageParserInterface newInstance) {
    instancesConnected.push_back(newInstance);
}

MessageParserInterface MessageParser_LoadBalancer
    ::disconnectInstance() {
    MessageParserInterface removedInstance = instancesConnected.back();
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

void MessageParser_LoadBalancer::newRequest(string mailData) {
    nextInstance =  (nextInstance + 1 ) % instancesConnected.size();
    auto pos = instancesConnected.cbegin();
    advance(pos, nextInstance);
    MessageParserInterface selectedInstance = *pos;
    Client newClient(selectedInstance.ipAddr, 8000, 8001);
    newClient.socket();
    newClient.bind();
    newClient.connect();
    newClient.send(mailData);
    newClient.close();
}

void MessageParser_LoadBalancer::runServer() {
    MPLBServer.socket();
    MPLBServer.bind();
    MPLBServer.listen(5000);
    std::ofstream ofile;
    ofile.open("./log.txt");
    while(true) {
        MPLBServer.accept();
        string messageInfo = MPLBServer.recv();
        auto t = std::chrono::system_clock::now();
        std::time_t tt = std::chrono::system_clock::to_time_t(t);
        std::string stt = ctime(&tt);
        std::string logString = tt + " " + messageInfo;
        ofile << logString << std::endl;
        if(strcmp(messageInfo.c_str(), "new connect") == 0) {
            MessageParserInterface newInstance {
                inet_ntoa(MPLBServer.getClientAddr().sin_addr)};
            connectInstance(newInstance);
        }
        else if(strcmp(messageInfo.c_str(), "disconnect") == 0) {
            disconnectInstance();
        }
        else {
            newRequest(messageInfo);
        }
    }
}