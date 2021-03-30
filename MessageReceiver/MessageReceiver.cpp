#include "MessageReceiver.hpp"
#include <iostream>
MessageReceiver::MessageReceiver(int port): MRServer(port) {}

void MessageReceiver::newMessage(string mailData) {
    std::cout << mailData;
    //TODO: IP待修改
    Client newClient("127.0.0.1", 8000,8001);
    newClient.socket();
    newClient.bind();
    newClient.connect();
    newClient.send(mailData);
    newClient.close();
}

void MessageReceiver::runServer() {
    MRServer.socket();
    MRServer.bind();
    MRServer.listen(500);
    while(true) {
        MRServer.accept();
        printf("accept client %s\n",
                inet_ntoa(MRServer.getClientAddr().sin_addr));
        string messageInfo = MRServer.recv();
        std::cout << messageInfo << std::endl;
        newMessage(messageInfo);
    }
}