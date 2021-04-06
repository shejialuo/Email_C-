#include "MailGenerator.hpp"
#include <iostream>
#include <unistd.h>
#include <chrono>
#include <fstream>

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
    ofstream ofile;
    ofile.open("./log.txt");
    while(true) {
        int currentNumberOfMessageRequired = numberOfMessagesRequiredInAMonitorWindow.at(i);
        i = (i + 1) % numberOfMessagesRequiredInAMonitorWindow.size();
        double timeBetweenTwoConsecutiveMessages = 
            static_cast<double>(monitoringWindowDimension) /static_cast<double>(currentNumberOfMessageRequired);

        int j = 0;
        while(j < currentNumberOfMessageRequired) {
            string mailData = "Message" + to_string(messageCounter);

            auto t = chrono::system_clock::now();
            std::time_t tt = chrono::system_clock::to_time_t(t);
            string stt = ctime(&tt);
            string logString = tt + " " + mailData;
            ofile << logString << endl;

            Client newClient("192.168.81.110", 8000, 8001);
            newClient.socket();
            newClient.bind();
            newClient.connect();
            newClient.send(mailData);
            newClient.close();

            messageCounter = messageCounter + 1;
            sleep(timeBetweenTwoConsecutiveMessages);
            j++;
        }
    }
}