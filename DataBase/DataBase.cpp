#include "DataBase.hpp"

Database::Database() {
    actualMessage = {};
    numberOfMessageInTheMonitoringWindow = 0;
    startAnalysisTimes = {};
    totalTime = 0;
    totalMessages = 0;
}


void Database::insertMessageInformation(string messageId, 
    int attachmentNumber) {
    int numberOfActivityWaiting = 3 + attachmentNumber;
    
  
    ++numberOfMessageInTheMonitoringWindow;

}

int Database::insertHeadersAnalysisResults(HeaderAnalysis res) {
    int numberOfActivityWaiting = -1;
}

int Database::insertAttachmentAnalysisResults(AttachmentAnalysis res) {
    int numberOfActivityWaiting = -1;

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