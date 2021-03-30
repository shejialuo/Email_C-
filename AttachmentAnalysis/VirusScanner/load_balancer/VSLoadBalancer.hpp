#ifndef VSLOADBALANCER_HPP
#define VSLOADBALANCER_HPP

#include <string>
#include <list>
#include "../../../Lib/Server.hpp"
#include "../../../Lib/Client.hpp"

using namespace std;

struct VirusScannerInterface {
    string ipAddr;
};

class VirusScanner_LoadBalancer {
private:
    list<VirusScannerInterface> instancesConnected;
    int nextInstance;
    Server VSLBServer;
public:
    //! 构造函数
    VirusScanner_LoadBalancer(int serverPort);
    //! 将新创建的VirusScanner加入instancesConnected
    void connectInstance(VirusScannerInterface newInstance);
    //! 删除指定的VirusScanner实例
    VirusScannerInterface disconnectInstance();
    //! 指定VirusScanner进行服务
    void newRequest(string attachment, string messageId);
    //! 启动Server程序与VirusScanner进行通信
    void runServer();
};

#endif // VSLOADBALANCER_HPP