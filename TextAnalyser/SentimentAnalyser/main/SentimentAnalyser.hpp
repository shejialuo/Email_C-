#ifndef TEXTANALYSER_HPP
#define TEXTANALYSER_HPP

#include <string>
using namespace std;

class TextAnalyser {


public:
    void analyzeText(string messageHeader, string messageBody,
                     string messageId);
    
};

#endif // TEXTANALYSER_HPP