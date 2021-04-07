#include "TextAnalyser.hpp"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <chrono>
#include <future>
#include <vector>
#include <sstream>

class SentimentAsyncCall {
private:
    Server SentimentAsyncCallServer;
public:
    SentimentAsyncCall(int serverPort):SentimentAsyncCallServer(serverPort) {
        SentimentAsyncCallServer.socket();
        SentimentAsyncCallServer.bind();
        SentimentAsyncCallServer.listen(5000);
    }
    void newRequest(string messageBody) {
        Client newClient("192.168.90.100",8000,8001);
        newClient.socket();
        newClient.bind();
        newClient.connect();
        newClient.send(messageBody);
        newClient.close();
    }
    string operator()(string messageBody) {
        newRequest(messageBody);
        SentimentAsyncCallServer.accept();
        string results = SentimentAsyncCallServer.recv();
        SentimentAsyncCallServer.close();
        return results;
    }
};

TextAnalyser::TextAnalyser(int serverPort): TAServer(serverPort) {
    Client newClient("192.168.88.110",8000,8001);
    newClient.socket();
    newClient.bind();
    newClient.connect();
    string messagesInfo = "new connect";
    newClient.send(messagesInfo); 
    newClient.close();
}

void TextAnalyser::analyzeText(string messageHeader,
    string messageBody,string messageId) {
    if(!messageHeader.empty()) {
        
    }
    string resultOfSentiment;
    if(!messageBody.empty()) {
        SentimentAsyncCall sentimentAsyncCall(8002);
        auto asyncCall = std::async(sentimentAsyncCall, messageBody);
        resultOfSentiment = asyncCall.get();
    }
    Client newClient("192.168.102.110", 8000, 8001);
    newClient.socket();
    newClient.bind();
    newClient.connect();
    string results = "Texts " + resultOfSentiment + " " + messageId; 
    newClient.send(results);
    newClient.close();
}

void TextAnalyser::runServer() {
    TAServer.socket();
    TAServer.bind();
    TAServer.listen(5000);
    std::ofstream ofile;
    ofile.open("./log.txt");
    while(true) {
        TAServer.accept();
        string messageInfo = TAServer.recv();
        auto t = std::chrono::system_clock::now();
        std::time_t tt = std::chrono::system_clock::to_time_t(t);
        std::string stt = ctime(&tt);
        std::string logString = tt + " " + messageInfo;
        ofile << logString << std::endl;
        if(strcmp(messageInfo.c_str(), "disconnect") == 0) {
            exit(0);
        }
        else {
            vector<string> param;
            istringstream iss(messageInfo);
            string token;
            while(getline(iss,token,' ')) {
                param.push_back(token);
            }
            string messageHeader = param.at(0);
            string messageBody = param.at(1);
            string messageId = param.at(2);
            analyzeText(messageHeader, messageBody, messageId);
        }
    }
}
