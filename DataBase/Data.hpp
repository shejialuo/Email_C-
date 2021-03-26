#ifndef DATA_HPP
#define DATA_HPP

#include <string>
#include <unordered_set>
using namespace std;

struct HeaderAnalysis {
    string haResults;
    string haMessageId;    
};

struct LinksAnalysis {
    string laResults;
    string laMessageId;
};

struct TextAnalysis {
    string taResults;
    string taMessageId;
};

struct AttachmentAnalysis {
    string aaResults;
    string aaMessageId;
};

struct Results {    
    int numberOfActivityWaiting;
    HeaderAnalysis headerAnalysisResults;
    LinksAnalysis linksAnalysisResults;
    TextAnalysis textAnalysisResults;
    unordered_multiset<AttachmentAnalysis> attachmentAnalysisResults;
};

#endif // DATA_HPP