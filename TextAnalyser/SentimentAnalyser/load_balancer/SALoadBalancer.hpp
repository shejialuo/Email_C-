#ifndef TALOADBALANCER_HPP
#define TALOADBALANCER_HPP

#include <string>
#include <list>
#include "../../Lib/Server.hpp"
#include "../../Lib/Client.hpp"

using namespace std;

struct TextAnalysisInterface {
    string ipAddr;
};

class TextAnalyser_LoadBalancer {
private:
    list<TextAnalysisInterface> instancesConnected;
    int nextInstance;
    Server TAServer;
public:
    //! 构造函数
    TextAnalyser_LoadBalancer(int serverPort);
    //! 将新创建的TextAnalyser加入instancesConnected
    void connectInstance(TextAnalysisInterface newInstance);
    //! 接收TextAnalyser发送的信息进而删除该实例
    TextAnalysisInterface disconnectInstance();
    //! 发送header至某个HeaderAnalyser实例
    void newRequest(string messageHeader, string messageBody, string messageId);
    //! 启动Server程序与HeaderAnalyser进行通信
    void runServer();
};

#endif // TALOADBALANCER_HPP