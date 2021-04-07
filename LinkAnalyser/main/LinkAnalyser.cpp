#include "LinkAnalyser.hpp"
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <chrono>

LinkAnalyser::LinkAnalyser(int serverPort): LAServer(serverPort) {
   Client newClient("192.168.84.110",8000,8001);
   newClient.socket();
   newClient.bind();
   newClient.connect();
   string messagesInfo = "new connect";
   newClient.send(messagesInfo); 
   newClient.close();
}

void LinkAnalyser::analyzeLinks(string links, string messageId) {
   Client newClient("192.168.102.110",8000,8001);
   newClient.socket();
   newClient.bind();
   newClient.connect();
   string linkAnalyisisResult = "Links " + links + " " + messageId;
   newClient.send(linkAnalyisisResult);
   newClient.close();
}

void LinkAnalyser::runServer() {
   LAServer.socket();
   LAServer.bind();
   LAServer.listen(5000);
   std::ofstream ofile;
   ofile.open("./log.txt");
   while(true) {
      LAServer.accept();
      string messageInfo = LAServer.recv();
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
         string links = param.at(0);
         string messageId = param.at(1);
         analyzeLinks(links, messageId);
      }
   }
}