#include "HeaderAnalyser.hpp"
#include "../../Data/HeaderAnalysis.hpp"
#include <iostream>
#include <vector>
#include <sstream>

HeaderAnalyser::HeaderAnalyser(int serverPort): HAServer(serverPort) {
   Client newClient("127.0.0.1",8000,8001);
   newClient.socket();
   newClient.bind();
   newClient.connect();
   string messagesInfo = "new connect";
   newClient.send(messagesInfo); 
   newClient.close();
}

void HeaderAnalyser::analyzeHeaders(string headers, string messageId) {

}

void HeaderAnalyser::runServer() {
   HAServer.socket();
   HAServer.bind();
   HAServer.listen(50);
   while(true) {
      HAServer.accept();
      string messageInfo = HAServer.recv();
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
         string headers = param.at(0);
         string messageId = param.at(1);
         analyzeHeaders(headers, messageId);
      }
   }
}