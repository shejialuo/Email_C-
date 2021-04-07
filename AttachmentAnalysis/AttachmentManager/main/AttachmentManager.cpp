#include "AttachmentManager.hpp"
#include <iostream>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <fstream>
#include <chrono>

AttachmentManager::AttachmentManager(int serverPort): AMServer(serverPort) {
    Client newClient("192.168.94.110",8000,8001);
    newClient.socket();
    newClient.bind();
    newClient.connect();
    string messagesInfo = "new connect";
    newClient.send(messagesInfo); 
    newClient.close();
}

void AttachmentManager::manageAttachments(string attachment, string messageId) {
    Client newClient("192.168.96.110",8000,8001);
    newClient.socket();
    newClient.bind();
    newClient.connect();
    string combined = attachment + " " + messageId;
    newClient.send(combined); 
    newClient.close();  
}

void AttachmentManager::runServer() {
    AMServer.socket();
    AMServer.bind();
    AMServer.listen(5000);
    std::ofstream ofile;
    ofile.open("./log.txt");
    while(true) {
      AMServer.accept();
      string messageInfo = AMServer.recv();
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
         string attachment = param.at(0);
         string messageId = param.at(1);
         manageAttachments(attachment, messageId);
      }
   }
}