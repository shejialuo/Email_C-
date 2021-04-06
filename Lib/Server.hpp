#ifndef SERVER_HPP
#define SERVER_HPP

#include <stdio.h>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string>
#include <unistd.h>

using std::string;

class Server {
private:
    int server_sockfd, client_sockfd;
    struct sockaddr_in serverAddr;
    struct sockaddr_in clientAddr;
    socklen_t addrLen;
    char buff[BUFSIZ];
public:
    Server(int port);
    int socket();
    int bind();
    int listen(int queue = 5);
    int accept();
    string recv();
    int close();
    struct sockaddr_in getClientAddr();
};

#endif // SERVER_HPP