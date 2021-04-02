#include "MessageParser.hpp"
#include <cstdlib>
#include <unordered_set>
#include <iostream>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/uuid/uuid_generators.hpp>

MessageParser::MessageParser(int serverPort): MPServer(serverPort) {
   //TODO: 修改IP地址为MessageParser_LoadBalancer
   Client newClient("127.0.0.1",8000,8001);
   newClient.socket();
   newClient.bind();
   newClient.connect();
   string messagesInfo = "new connect";
   newClient.send(messagesInfo); 
   newClient.close();
}

void MessageParser::headerAnalyserNewRequest(
    string header, string messageId) {
    //TODO: 修改IP地址为HeaderAnalyser_LoadBalancer
   Client newClient("127.0.0.1",8000,8001);
   newClient.socket();
   newClient.bind();
   newClient.connect();
   string combinedString = header + " " + messageId;
   newClient.send(combinedString); 
   newClient.close();
}


void MessageParser::textAnalyserNewqRequest(
    string messageHeader, string messageBody,
    string messageId) {
    
}




void MessageParser::parseMessage(string mailData) {
    string headers = mailData + "_NetworkHeaders";
    string sender = mailData + "_Sender";
    string messageHeader = mailData + "_MessageHeader";
    string messageBody = mailData + "_MessageBody";
    unordered_multiset<string> links;
    unordered_multiset<string> attachments;

    int numberOfLinks = rand() % 11 ;
    if(numberOfLinks > 0) {
        int i = 0;
        while (i < numberOfLinks) {
            string link = mailData + "_Link" + to_string(i);
            links.insert(link);
            ++i;
        }
    }
    else {
        links = {};
    }

    int numberOfAttachments = rand() % 5;
    if(numberOfAttachments > 0) {
        int i = 0;
        while(i < numberOfAttachments) {
            string attachment = mailData + "_Attachment" + to_string(i);
            attachments.insert(attachment);
        }
    }
    else {
        attachments = {};
    }

    MessageFields messageFields = {
        headers, sender, messageHeader, 
        messageBody, links, attachments
    };

    boost::uuids::uuid newUuid = boost::uuids::random_generator()();
    string messageId = boost::uuids::to_string(newUuid);
    
    headerAnalyserNewRequest(messageFields.headers, messageId);
    
    
    
    textAnalyserNewqRequest(messageFields.messageHeader,
                            messageFields.messageBody ,messageId);
                            
    if(!attachments.empty()) {
        for(auto &attachment:messageFields.attachments) {
            attachmentAnalyserNewRequest(attachment,messageId);
        }
        attachments.clear();
    }
}

void MessageParser::runServer() {
    MPServer.socket();
    MPServer.bind();
    //TODO:是否需要修改listen的数值
    MPServer.listen(50);
    while(true) {
        MPServer.accept();
        string messageInfo = MPServer.recv();
        std::cout << messageInfo << std::endl;
        if(strcmp(messageInfo.c_str(), "disconnect") == 0) {
            exit(0);   
        }
        else {
            parseMessage(messageInfo);
        }
    }
}