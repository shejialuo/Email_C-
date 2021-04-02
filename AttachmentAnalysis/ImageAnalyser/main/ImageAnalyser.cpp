#include "ImageAnalyser.hpp"

#include <iostream>
#include <vector>
#include <sstream>

ImageAnalyser::ImageAnalyser(int serverPort): IAServer(serverPort) {
   //TODO: 修改IP地址
   Client newClient("127.0.0.1",8000,8001);
   newClient.socket();
   newClient.bind();
   newClient.connect();
   string messagesInfo = "new connect";
   newClient.send(messagesInfo); 
   newClient.close();
}

void ImageAnalyser::analyzeImage(string image, string messageId) {

}

void ImageAnalyser::runServer() {
   IAServer.socket();
   IAServer.bind();
   IAServer.listen(50);
   while(true) {
      IAServer.accept();
      string messageInfo = IAServer.recv();
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
         string image = param.at(0);
         string messageId = param.at(1);
         analyzeImage(image, messageId);
      }
   }
}