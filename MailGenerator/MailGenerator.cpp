#include "MailGenerator.hpp"
#include <iostream>
using namespace std;


MailGenerator::MailGenerator() {
    messageCounter = 0;
    //TODO: 后续修改窗口。
    numberOfMessagesRequiredInAMonitorWindow = {};
    monitoringWindowDimension = 200;
}

void MailGenerator::run() {
    while(true) {

        int i = 0;
        int currentNumberOfMessageRequired = numberOfMessagesRequiredInAMonitorWindow.at(i);
        i = (i + 1) % numberOfMessagesRequiredInAMonitorWindow.size();
        double timeBetweenTwoConsecutiveMessages = 
            static_cast<double>(monitoringWindowDimension) /static_cast<double>(currentNumberOfMessageRequired);
        //* 测试
        cout << currentNumberOfMessageRequired;
        int j = 0;
        while(j < currentNumberOfMessageRequired) {
            //TODO: 传递，应该在类里增加一个函数。
            //? messageCounter设置的为int，是否合理？
            messageCounter = messageCounter + 1;
            //TODO: 实现休眠，标准库无函数，此处Windows和Linux不同，是否考虑全平台？
            j++;
        }
    }
}