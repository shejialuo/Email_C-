#include "NSFWDetector.hpp"
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <chrono>

NSFWDetector::NSFWDetector(int serverPort):NDServer(serverPort) {
    yesOrNot = -1;
}

void NSFWDetector::nsfwDetection(string image, string ip) {
    yesOrNot += 1;
    Client newClient(ip,8002,8001);
    newClient.socket();
    newClient.bind();
    newClient.connect();
    if (yesOrNot % 3 == 0) {
        newClient.send("false");
    }
    else {
        newClient.send("true");
    }
    newClient.close();
}

void NSFWDetector::runServer() {
    NDServer.socket();
    NDServer.bind();
    NDServer.listen(5000);
    ofstream ofile;
    ofile.open("./log.txt");
    while(true) {
        NDServer.accept();
        string messageInfo = NDServer.recv();
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
            nsfwDetection(image, ip);
        }
    }
}