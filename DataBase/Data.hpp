#ifndef DATA_HPP
#define DATA_HPP

#include <string>
#include <unordered_set>
#include "../Data/AttachmentAnalysis.hpp"
#include "../Data/TextAnalysis.hpp"
#include "../Data/HeaderAnalysis.hpp"
#include "../Data/LinksAnalysis.hpp"
using namespace std;

struct Results {    
    int numberOfActivityWaiting;
    HeaderAnalysis headerAnalysisResults;
    LinksAnalysis linksAnalysisResults;
    TextAnalysis textAnalysisResults;
    unordered_multiset<AttachmentAnalysis> attachmentAnalysisResults;
    Results(
        int num, HeaderAnalysis haResults,
        LinksAnalysis laResults, TextAnalysis taResults,
        unordered_multiset<AttachmentAnalysis> aaResults)
        : numberOfActivityWaiting(num),
          headerAnalysisResults(haResults), linksAnalysisResults(laResults),
          textAnalysisResults(taResults), attachmentAnalysisResults(aaResults){}

};

#endif // DATA_HPP