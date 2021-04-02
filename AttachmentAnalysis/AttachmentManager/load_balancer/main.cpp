#include "AMLoadBalancer.hpp"

int main() {
    AttachmentManager_LoadBalancer AMLoader(8000);
    AMLoader.runServer();
    return 0;
}