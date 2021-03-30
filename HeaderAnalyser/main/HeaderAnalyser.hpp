#ifndef HEADERANALYSER_HPP
#define HEADERANALYSER_HPP

#include <string>
#include "../../Lib/Server.hpp"
#include "../../Lib/Client.hpp"
using namespace std;

class HeaderAnalyser {
private:
    Server HAServer;
public:
    //! 构造函数用于将ip地址通过socket发送给HeaderAnayser_LoadBalancer
    HeaderAnalyser(int serverPort);
    //! 实现分析功能，并将结果传递给MessageAnalyser
    void analyzeHeaders(string headers, string messageId);
    //! 运行server以便接收LoadBalancer的请求
    void runServer();
};

#endif // HEADERANALYSER_HPP