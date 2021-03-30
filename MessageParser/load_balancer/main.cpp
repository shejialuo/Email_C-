// 与MPLoadBalancer.cpp
// ../../Lib/Client.cpp
// ../../Lib/Server.cpp编译
#include "MPLoadBalancer.hpp"

int main() {
    MessageParser_LoadBalancer MPLoader(8000);
    MPLoader.runServer();
    return 0;
}