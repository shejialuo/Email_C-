#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <stdio.h>
#include <unistd.h>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string>
using std::string;

#define BUFFSIZE 100000

class Client {
private:
    int sockfd;
    struct sockaddr_in serverAddr;
    struct sockaddr_in clientAddr;
    socklen_t addrLen;
    char buff[BUFFSIZE];
public:
    Client(string serverIp, int serverPort, int clientPort);
    int socket();
    int bind();
    int connect();
    int send(string messageInfo);
    int close();
};

#endif // CLIENT_HPP