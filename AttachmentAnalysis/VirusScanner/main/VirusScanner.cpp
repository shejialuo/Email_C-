#include "VirusScanner.hpp"
#include "../../Data/AttachmentAnalysis.hpp"
#include <iostream>
#include <vector>
#include <sstream>
#include <cstdlib>

VirusScanner::VirusScanner(int serverPort): VSServer(serverPort) {
   //TODO: 修改ip地址为VirusScanner_LoadBalancer。
   Client newClient("127.0.0.1",8000,8001);
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
      AttachmentAnalysis res("VirusFound from VirusScanner in attachment: " + attachment,
                              messageId);
      //TODO: 发送AttachmentAnalysis至messageAnalyserLoadBalancer
   }
   else {
      //TODO: 修改ip地址为attachmentManager_LoadBalancer。
      Client newClient("127.0.0.1",8000,8001);
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
   VSServer.listen(50);
   while(true) {
      VSServer.accept();
      string messageInfo = VSServer.recv();
      std::cout << messageInfo << std::endl;
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