#include "MailGenerator.hpp"
#include <iostream>
#include <unistd.h>
using namespace std;


MailGenerator::MailGenerator() {
    messageCounter = 0;
    numberOfMessagesRequiredInAMonitorWindow = {
        10, 10, 10, 10, 10, 10, 10,
		30, 30, 30, 30, 30, 30, 30,
		80, 80, 80, 80, 80, 80, 80,
		160, 160, 160, 160, 160, 160, 160,
		180, 180, 180, 180, 180, 180, 180,
		100, 100, 100, 100, 100, 100, 100,
		80, 80, 80, 80, 80, 80, 80,
		60, 60, 60, 60, 60, 60, 60
    };
    monitoringWindowDimension = 200;
}

void MailGenerator::run() {
    int i = 0;
    while(true) {
        int currentNumberOfMessageRequired = numberOfMessagesRequiredInAMonitorWindow.at(i);
        i = (i + 1) % numberOfMessagesRequiredInAMonitorWindow.size();
        double timeBetweenTwoConsecutiveMessages = 
            static_cast<double>(monitoringWindowDimension) /static_cast<double>(currentNumberOfMessageRequired);
        //* 测试
        cout << currentNumberOfMessageRequired;
        int j = 0;
        while(j < currentNumberOfMessageRequired) {
            string mailData = "Message" + to_string(messageCounter);
            // TODO: ip地址待修改
            Client newClient("127.0.0.1", 8000, 8001);
            newClient.socket();
            newClient.bind();
            newClient.connect();
            newClient.send(mailData);
            newClient.close();
            messageCounter = messageCounter + 1;
            sleep(timeBetweenTwoConsecutiveMessages);
            j++;
            cout << j << endl;
        }
    }
}