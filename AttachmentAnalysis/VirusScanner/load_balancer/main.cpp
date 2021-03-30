#include "VSLoadBalancer.hpp"

int main() {
    VirusScanner_LoadBalancer VSLoader(8000);
    VSLoader.runServer();
    return 0; 
}