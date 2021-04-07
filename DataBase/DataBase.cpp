#include "DataBase.hpp"

#include <iostream>
#include <chrono>
#include <fstream>
#include <vector>
#include <sstream>

Database::Database(int serverPort): DBServer(serverPort) {
    actualMessage = {};
    numberOfMessageInTheMonitoringWindow = 0;
    startAnalysisTimes = {};
    totalTime = 0;
    totalMessages = 0;
}

void Database::insertMessageInformation(string ip, string messageId, 
    int LinkNumber, int attachmentNumber) {
    int numberOfActivityWaiting = 2 + LinkNumber + attachmentNumber;
    unordered_multiset<AttachmentAnalysis> attachmentAnalysis {"",""};
    Results newResults = Results(numberOfActivityWaiting,
                                  HeaderAnalysis("",""),
                                  LinksAnalysis("",""),
                                  TextAnalysis("",""),
                                  attachmentAnalysis);
    actualMessage.insert({messageId,newResults});
    auto t = std::chrono::system_clock::now();
    std::time_t tt = std::chrono::system_clock::to_time_t(t);
    std::string stt = ctime(&tt);
    startAnalysisTimes.insert({messageId, stt});
    ++numberOfMessageInTheMonitoringWindow;
    Client newClient(ip, 8002,8001);
    newClient.socket();
    newClient.bind();
    newClient.connect();
    newClient.send("OK");
    newClient.close();
}

int Database::insertHeadersAnalysisResults(HeaderAnalysis res) {
    int numberOfActivityWaiting = -1;


    return numberOfActivityWaiting;
}

int Database::insertAttachmentAnalysisResults(AttachmentAnalysis res) {
    int numberOfActivityWaiting = -1;
    

    return numberOfActivityWaiting;
}

int Database::getNumberOfMessagesInTheMonitoringWindow() {
    return numberOfMessageInTheMonitoringWindow;
}

void Database::resetNumberOfMessagesInTheMonitoringWindow() {
    numberOfMessageInTheMonitoringWindow = 0;
}

double Database::getAverageAnalysisTime() {
    double averageTime = 0;
    if (totalMessages != 0) {
        averageTime = totalTime / static_cast<double>(totalMessages);
    }
    return averageTime;
}

void Database::resetAverageAnalysisTime() {
    totalMessages = 0;
    totalTime = 0;
}

void Database::runServer() {
    DBServer.socket();
    DBServer.bind();
    DBServer.listen(5000);
    std::ofstream ofile;
    ofile.open("./log.txt");
    while(true) {
        DBServer.accept();
        string ip = inet_ntoa(DBServer.getClientAddr().sin_addr);
        string messageInfo = DBServer.recv();
        auto t = std::chrono::system_clock::now();
        std::time_t tt = std::chrono::system_clock::to_time_t(t);
        std::string stt = ctime(&tt);
        std::string logString = tt + " " + messageInfo;
        ofile << logString << std::endl;
        vector<string> param;
        istringstream iss(messageInfo);
        string token;
        while(getline(iss,token,' ')) {
            param.push_back(token);
        }
        token = param.at(0);
        if(strcmp(token.c_str(), "Headers") == 0) {

        }
        else if()
        else {
            insertMessageInformation(ip,param.at(0),
             std::stoi(param.at(1)), std::stoi(param.at(2)));
        }
    }
}