#include "VirusScanner.hpp"
#include <iostream>
#include <vector>
#include <sstream>

VirusScanner::VirusScanner(int serverPort): VSServer(serverPort) {
   Client newClient("127.0.0.1",8000,8001);
   newClient.socket();
   newClient.bind();
   newClient.connect();
   string messagesInfo = "new connect";
   newClient.send(messagesInfo); 
   newClient.close();
}

void VirusScanner::scanAttachment(string headers, string messageId) {
    
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