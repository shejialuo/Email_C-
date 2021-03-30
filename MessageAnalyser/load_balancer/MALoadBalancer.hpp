#ifndef MALOADBALANCER_HPP
#define MALOADBALANCER_HPP

#include <string>
#include <list>
#include "../../Lib/Server.hpp"
#include "../../Lib/Client.hpp"
#include "../../Data/AttachmentAnalysis.hpp"
#include "../../Data/TextAnalysis.hpp"
#include "../../Data/HeaderAnalysis.hpp"
#include "../../Data/LinksAnalysis.hpp"

using namespace std;

struct MessageAnalysisInterface {
    string ipAddr;
};

class MessageAnalyser_LoadBalancer {
private:
    list<MessageAnalysisInterface> instancesConnected;
    int nextInstance;
    Server MALBServer;
public:
    MessageAnalyser_LoadBalancer(int serverPort);
    void connectInstance(MessageAnalysisInterface newInstance);
    MessageAnalysisInterface disconnectInstance();
    void insertHeadersAnalysisResults(HeadersAnalysis res);
	void insertLinksAnalysisResults(LinksAnalysis res);
	void insertTextAnalysisResults(TextAnalysis res);
	void insertAttachmentAnalysisResults(AttachmentAnalysis res);
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

#endif // MALOADBALANCER_HPP