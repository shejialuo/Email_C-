#ifndef MESSAGEPARSER_HPP
#define MESSAGEPARSER_HPP

#include <string>
#include "../../Lib/Server.hpp"
#include "../../Lib/Client.hpp"
using namespace std;

class MessageParser {
private:
    Server MPServer;
public:
    //! 解析邮件
    void parseMessage(string mailData);

};

#endif // MESSAGEPARSER_HPP