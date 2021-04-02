#include "Lib/Client.hpp"


int main() {
    Client newClient("192.168.110.110", 8000,8001);
    while(true) {
        newClient.socket();
        newClient.bind();
        newClient.connect();
        newClient.send("hello world");
        newClient.close();
    }
    return 0;
}