#ifndef MAILRECEIVER_HPP
#define MAILRECEIVER_HPP

#include "../Lib/Server.hpp"
#include "../Lib/Client.hpp"

class MessageReceiver {
private:
    Server MRServer;
public:
    //! 构造函数
    MessageReceiver(int port);
    //! 传递信息至MessageParser_LoadBalancer
    void newMessage(string mailData);
    //! 运行MRServer
    void runServer();
};

#endif // MAILRECEIVER_HPP