#include "MessageReceiver.hpp"

int main() {
    MessageReceiver messageReceiver(8000);
    messageReceiver.runServer();
    return 0;
}