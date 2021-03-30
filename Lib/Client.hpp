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

class Client {
private:
    //! 定义套接字
    int sockfd;
    //! 定义Server地址信息
    struct sockaddr_in serverAddr;
    //! 定义Client地址信息
    struct sockaddr_in clientAddr;
    //! 定义套接字长度
    socklen_t addrLen;
    //! 定义缓冲区
    char buff[BUFSIZ];
public:
    //! 构造函数
    Client(string serverIp, int serverPort, int clientPort);
    //! 创建套接字
    int socket();
    //! 实现绑定功能，进行封装
    int bind();
    //! 实现连接功能，进行封装
    int connect();
    //! 实现发送功能，进行封装
    int send(string messageInfo);
    //! 关闭套接字，进行封装
    int close();
};

#endif // CLIENT_HPP