#include "TALoadBalancer.hpp"
#include <iterator>
#include <iostream>

TextAnalyser_LoadBalancer::TextAnalyser_LoadBalancer(
    int serverPort): TAServer(serverPort){
    instancesConnected = {};
    nextInstance = -1;    
}

TextAnalysisInterface TextAnalyser_LoadBalancer
    ::disconnectInstance() {
    TextAnalysisInterface removedInstance = instancesConnected.back();
    instancesConnected.pop_back();
    return removedInstance;
}

void TextAnalyser_LoadBalancer::connectInstance(
    TextAnalysisInterface newInstance) {
    instancesConnected.push_back(newInstance);
}

void TextAnalyser_LoadBalancer::newRequest(
    string headers, string messageId) {
    nextInstance =  ++nextInstance % instancesConnected.size();
    auto pos = instancesConnected.cbegin();
    advance(pos, nextInstance);
    TextAnalysisInterface selectedInstance = *pos;
    Client newClient(selectedInstance.ipAddr, 8000, 8001);
    newClient.socket();
    newClient.bind();
    newClient.connect();
    newClient.send("new request");
    newClient.send(headers);
    newClient.send(messageId);
    newClient.close();
}


void TextAnalyser_LoadBalancer::runServer() {
    TAServer.socket();
    TAServer.bind();
    TAServer.listen(500);
    while(true) {
        TAServer.accept();
        printf("accept client %s\n",
                inet_ntoa(TAServer.getClientAddr().sin_addr));
        string messageInfo = TAServer.recv();
        std::cout << messageInfo << std::endl;

        if(strcmp(messageInfo.c_str(), "new connect") == 0) {
            TextAnalysisInterface newInstance {
                inet_ntoa(TAServer.getClientAddr().sin_addr)};
            connectInstance(newInstance);
        }

        if(strcmp(messageInfo.c_str(), "new request") == 0) {
            string headers = HAServer.recv();
            string messageId = HAServer.recv();
            newRequest(headers, messageId);
        }
        if(strcmp(messageInfo.c_str(), "disconnect") == 0) {
            disconnectInstance();
        }
    }
}