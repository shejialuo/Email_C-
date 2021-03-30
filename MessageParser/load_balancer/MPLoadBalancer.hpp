#ifndef MPLOADBALANCER_HPP
#define MPLOADBALANCER_HPP

#include <string>
#include <list>
#include "../../Lib/Server.hpp"
#include "../../Lib/Client.hpp"

using namespace std;

struct MessageParserInterface {
    string ipAddr;
};

class MessageParser_LoadBalancer {
private:
    list<MessageParserInterface> instancesConnected;
    int nextInstance;
    Server MPLBServer;
public:
    //!构造函数
    MessageParser_LoadBalancer(int serverPort);
    //! 将新创建的MessageParser加入instancesConnected
    void connectInstance(MessageParserInterface newInstance);
    //! 删除指定的MessageParser实例
    MessageParserInterface disconnectInstance();
    //! 指定MessageParser进行服务
    void newRequest(string mailData);
    //! 启动Server程序与HeaderAnalyser进行通信
    void runServer();
};


#endif // MPLOADBALANCER_HPP