#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <unordered_map>
#include <string>
#include "Data.hpp"
using namespace std;

class Database {
private:
    unordered_map<string, Results> actualMessage;
    int numberOfMessageInTheMonitoringWindow;
    unordered_map<string, double> startAnalysisTimes;
    double totalTime;
    int totalMessages;
public:
    //! 构造函数
    Database();
    //! 插入消息的基本信息
    void insertMessageInformation(string messageId, int attachmentsNumber);
    //! 插入Header分析结果，并返回numberOfActivityWaiting
    int insertHeadersAnalysisResults(HeaderAnalysis res);
    //! 插入Link分析结果，并返回numberOfActivityWaiting
    int insertLinksAnalysisResults(LinksAnalysis res);
    //! 插入text分析结果，并返回numberOfActivityWaiting
    int insertTextAnalysisResults(TextAnalysis res);
    //! 插入attachment分析结果，并返回numberOfActivityWaiting
    int insertAttachmentAnalysisResults(AttachmentAnalysis res);
    //! 根据messageId得到Results
    Results getMessageResults(string messageId);
    //! 得到位于监控窗口的消息数
    int getNumberOfMessagesInTheMonitoringWindow();
    //! 重置位于监控窗口的消息数
    void resetNumberOfMessagesInTheMonitoringWindow();
    //! 得到平均分析时间
    double getAverageAnalysisTime();
    //! 重置平均分析时间
    void resetAverageAnalysisTime();
};

#endif // DATABASE_HPP