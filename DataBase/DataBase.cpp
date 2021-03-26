#include "DataBase.hpp"

Results Database::getMessageResults(string messageId) {
    
}

int Database::getNumberOfMessagesInTheMonitoringWindow() {
    return numberOfMessageInTheMonitoringWindow;
}

void Database::resetNumberOfMessagesInTheMonitoringWindow() {
    numberOfMessageInTheMonitoringWindow = 0;
}

double Database::getAverageAnalysisTime() {
    double averageTime = 0;
    if (totalMessages != 0) {
        averageTime = totalTime / static_cast<double>(totalMessages);
    }
    return averageTime;
}

void Database::resetAverageAnalysisTime() {
    totalMessages = 0;
    totalTime = 0;
}