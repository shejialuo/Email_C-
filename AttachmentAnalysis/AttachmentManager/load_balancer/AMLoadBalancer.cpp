#ifndef AMLOADBALANCER_HPP
#define AMLOADBALANCER_HPP

#include <string>
#include <list>
#include "../../../Lib/Server.hpp"

using namespace std;
struct AttachmentManagementInterface {
    struct sockaddr_in clientAddr;
};

class LinkAnalyser_LoadBalancer {
private:
    list<LinkAnalysisInterface> instancesConnected;
    int nextInstance;
    Server LAServer;
public:
    //! 构造函数
    HeaderAnalyser_LoadBalancer(int port);
    //! 将新创建的HeaderAnalyser加入instancesConnected
    void connectInstance(HeaderAnalysisInterface newInstance);
    //! 接收HeaderAnalyser发送的信息删除该实例
    HeaderAnalyser_LoadBalancer disconnectInstance();
    //! 发送header至某个HeaderAnalyser实例
    void newRequest(string headers, string messageId);
    //! 启动程序
    void run();
};

#endif // HALOADBALANCER_HPP