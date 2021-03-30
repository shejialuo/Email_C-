#ifndef MAILGENERATOR_HPP
#define MAILGENERATOR_HPP

#include "../Lib/Client.hpp"

#include <vector>
using namespace std;

class MailGenerator {
private:
    //! 定义消息数
    int messageCounter;
    //! 定义在某一窗口的消息数
    vector<int> numberOfMessagesRequiredInAMonitorWindow;
    //! 定义窗口维度
    int monitoringWindowDimension;
public:
    //! 构造函数
    MailGenerator();
    //! 运行程序入口
    void run();
};


#endif // MAILGENERATOR_HPP