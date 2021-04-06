#include "MessageReceiver.hpp"
#include <iostream>
#include <chrono>
#include <fstream>

MessageReceiver::MessageReceiver(int port): MRServer(port) {}

void MessageReceiver::newMessage(string mailData) {
    Client newClient("192.168.82.110", 8000,8001);
    newClient.socket();
    newClient.bind();
    newClient.connect();
    newClient.send(mailData);
    newClient.close();
}

void MessageReceiver::runServer() {
    MRServer.socket();
    MRServer.bind();
    MRServer.listen(5000);
    std::ofstream ofile;
    ofile.open("./log.txt");

    while(true) {
        MRServer.accept();
        std::string messageInfo = MRServer.recv();
        auto t = std::chrono::system_clock::now();
        std::time_t tt = std::chrono::system_clock::to_time_t(t);
        std::string stt = ctime(&tt);
        std::string logString = stt + " " + messageInfo;
        ofile << logString << std::endl;
        newMessage(messageInfo);
    }
}