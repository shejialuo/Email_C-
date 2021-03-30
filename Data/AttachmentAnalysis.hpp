#ifndef ATTATCHMENTANALYSIS_HPP
#define ATTATCHMENTANALYSIS_HPP

#include <string>

struct AttachmentAnalysis {
    std::string aaResults;
    std::string aaMessageId;
    AttachmentAnalysis(std::string results, std::string messageId) {
        aaResults = results;
        aaMessageId = messageId;
    }
};


#endif // ATTATCHMENTANALYSIS_HPP