#include "IALoadBalancer.hpp"

int main() {
    ImageAnalyser_LoadBalancer IALoader(8000);
    IALoader.runServer();
    return 0;
}