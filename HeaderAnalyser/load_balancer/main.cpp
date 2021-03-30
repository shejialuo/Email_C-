// 与HeaderAnalyser.cpp和 
// ../../Lib/Client.cpp
// ../../Lib/Server.cpp编译
#include "HALoadBalancer.hpp"

int main() {
    HeaderAnalyser_LoadBalancer HALoader(8000);
    HALoader.runServer();
    return 0;
}