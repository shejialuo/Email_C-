#include "SentimentAnalyser.hpp"
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <chrono>

SentimentAnalyser::SentimentAnalyser(int serverPort): SAServer(serverPort) {}

void SentimentAnalyser::analyzeSentiment(string messageBody, string ip) {
    Client newClient(ip,8002,8001);
    newClient.socket();
    newClient.bind();
    newClient.connect();
    newClient.send("SentimentAnalysis");
    newClient.close();
}

void SentimentAnalyser::runServer() {
    SAServer.socket();
    SAServer.bind();
    SAServer.listen(5000);
    ofstream ofile;
    ofile.open("./log.txt");
    while(true) {
        SAServer.accept();
        string messageInfo = SAServer.recv();
        auto t = chrono::system_clock::now();
        std::time_t tt = chrono::system_clock::to_time_t(t);
        string stt = ctime(&tt);
        string logString = tt + " " + messageInfo;
        ofile << logString << endl;
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
            string messageBody = param.at(0);
            string ip = param.at(1);
            analyzeSentiment(messageBody, ip);
        }
    }
}