#include "VirusScanner.hpp"
#include <iostream>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <fstream>
#include <chrono>

VirusScanner::VirusScanner(int serverPort): VSServer(serverPort) {
   Client newClient("192.168.92.110",8000,8001);
   newClient.socket();
   newClient.bind();
   newClient.connect();
   string messagesInfo = "new connect";
   newClient.send(messagesInfo); 
   newClient.close();
}

void VirusScanner::scanAttachment(string attachment, string messageId) {
   bool virusFound = rand() % 5 == 0;
   if(virusFound) {
      string res = "Attachments " + attachment + " " + messageId + " VirusFound";
      Client newClient("192.168.102.110",8000,8001);
      newClient.socket();
      newClient.bind();
      newClient.connect();
      newClient.send(res); 
      newClient.close();
   }
   else {
      Client newClient("192.168.94.110",8000,8001);
      newClient.socket();
      newClient.bind();
      newClient.connect();
      string combined = attachment + " " + messageId;
      newClient.send(combined); 
      newClient.close();
   }
}

void VirusScanner::runServer() {
   VSServer.socket();
   VSServer.bind();
   VSServer.listen(5000);
   std::ofstream ofile;
   ofile.open("./log.txt");
   while(true) {
      VSServer.accept();
      string messageInfo = VSServer.recv();
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
         scanAttachment(attachment, messageId);
      }
   }
}