#include "MessageAnalyser.hpp"

#include <iostream>
#include <vector>
#include <sstream>
#include <future>
#include <thread>
#include <fstream>
#include <chrono>

class DBAnalysis {
private:
    Server DBServer;
public:
    DBAnalysis(int serverPort): DBServer(serverPort) {}
    void newRequest(string res) {
        Client newClient("192.168.104.110",8000,8001);
        newClient.socket();
        newClient.bind();
        newClient.connect();
        newClient.send(res);
        newClient.close();
    }
    string operator()(string res) {
        DBServer.socket();
        DBServer.bind();
        DBServer.listen(5000);
        DBServer.accept();
        string numberOfActivityWaiting = DBServer.recv();
        return numberOfActivityWaiting;
    }
};

void MessageAnalyser::insertHeadersAnalysisResults(string res) {
    DBAnalysis DBAsyncCall(8002);
    auto futureResults = std::async(DBAsyncCall, res);
    int numberOfActivityWaiting = std::stoi(futureResults.get());
    if(numberOfActivityWaiting == 0) {
        
    }
}

void MessageAnalyser::insertLinksAnalysisResults(string res) {
    DBAnalysis DBAsyncCall(8003);
    auto futureResults = std::async(DBAsyncCall, res);
    int numberOfActivityWaiting = std::stoi(futureResults.get());
    if(numberOfActivityWaiting == 0) {

    }
}

void MessageAnalyser::insertTextAnalysisResults(string res) {
    DBAnalysis DBAsyncCall(8004);
    auto futureResults = std::async(DBAsyncCall, res);
    int numberOfActivityWaiting = std::stoi(futureResults.get());
    if(numberOfActivityWaiting == 0) {

    }
}

void MessageAnalyser::insertAttachmentAnalysisResults(string res) {
    DBAnalysis DBAsyncCall(8005);
    auto futureResults = std::async(DBAsyncCall, res);
    int numberOfActivityWaiting = std::stoi(futureResults.get());
    if(numberOfActivityWaiting == 0) {

    }
}

void takeFinalDecision(string messageId) {
    
}

void MessageAnalyser::runServer() {
    MAServer.socket();
    MAServer.bind();
    MAServer.listen(5000);
    std::ofstream ofile;
    ofile.open("./log.txt");
    while(true) {
        MAServer.accept();
        string messageInfo = MAServer.recv();
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
            token = param.at(0);
            if(strcmp(token.c_str(), "Headers") == 0) {
                insertHeadersAnalysisResults(messageInfo);
            }
            else if(strcmp(token.c_str(), "Links") == 0) {
                insertLinksAnalysisResults(messageInfo);
            }
            else if(strcmp(token.c_str(), "Texts")) {
                insertTextAnalysisResults(messageInfo);
            }
            else {
                insertAttachmentAnalysisResults(messageInfo);
            }
        }
    }
}