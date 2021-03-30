#ifndef HALOADBALANCER_HPP
#define HALOADBALANCER_HPP

#include <string>
#include <list>
#include "../../Lib/Server.hpp"
#include "../../Lib/Client.hpp"

using namespace std;

struct HeaderAnalysisInterface {
    string ipAddr;
};

class HeaderAnalyser_LoadBalancer {
private:
    list<HeaderAnalysisInterface> instancesConnected;
    int nextInstance;
    Server HALBServer;
public:
    //! 构造函数
    HeaderAnalyser_LoadBalancer(int serverPort);
    //! 将新创建的HeaderAnalyser加入instancesConnected
    void connectInstance(HeaderAnalysisInterface newInstance);
    //! 删除指定的MessageParser实例
    HeaderAnalysisInterface disconnectInstance();
    //! 指定HeaderAnalyser进行服务
    void newRequest(string headers, string messageId);
    //! 启动Server程序与HeaderAnalyser进行通信
    void runServer();
};

#endif // HALOADBALANCER_HPP