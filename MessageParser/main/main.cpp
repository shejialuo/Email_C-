#include "MessageParser.hpp"

int main() {
    MessageParser messageParser(8000);
    messageParser.runServer();
    return 0;
}