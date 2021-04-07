#include "ImageRecognizer.hpp"
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <chrono>

ImageRecognizer::ImageRecognizer(int serverPort):IRServer(serverPort) {
    category = -1;
}

void ImageRecognizer::recognizeImage(string image, string ip) {
    category = category + 1;
    Client newClient(ip,8003,8001);
    newClient.socket();
    newClient.bind();
    newClient.connect();
    string results = "Category" + to_string(category);
    newClient.send(results);
    newClient.close();
}

void ImageRecognizer::runServer() {
    IRServer.socket();
    IRServer.bind();
    IRServer.listen(5000);
    ofstream ofile;
    ofile.open("./log.txt");
    while(true) {
        IRServer.accept();
        string messageInfo = IRServer.recv();
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
            string image = param.at(0);
            string ip = param.at(1);
            recognizeImage(image, ip);
        }
    }
}