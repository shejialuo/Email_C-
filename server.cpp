#include "Lib/Server.hpp"
#include <string>
#include <iostream>
#include <fstream>
int main() {
    Server server(8000);
    server.socket();
    server.bind();
    server.listen();
    std::ofstream ofile;
    ofile.open("./log.txt");
    while(true) {
        server.accept();
        std::string a = server.recv();
        ofile << a << std::endl;
    }
    return 0;
}