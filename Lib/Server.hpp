#ifndef SERVER_HPP
#define SERVER_HPP

#include <stdio.h>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string>
using std::string;

class Server {
private:
    //! 定义Sever、Client套接字
    int server_sockfd, client_sockfd;
    //! 定义Server地址信息
    struct sockaddr_in serverAddr;
    //! 定义Client地址信息
    struct sockaddr_in clientAddr;
    //! 定义套接字长度
    socklen_t addrLen;
    //! 定义缓冲区
    char buff[BUFSIZ];
public:
    //! 构造函数初始化
    Server(int port);
    //! 创建套接字
    int socket();
    //! 实现绑定功能，进行封装
    int bind();
    //! 实现监听功能，进行封装
    int listen(int queue = 5);
    //! 实现接收链接功能，进行封装
    int accept();
    //! 实现接收数据功能，进行封装
    string recv();
    //! 返回客户端地址
    struct sockaddr_in getClientAddr();
};

#endif // SERVER_HPP