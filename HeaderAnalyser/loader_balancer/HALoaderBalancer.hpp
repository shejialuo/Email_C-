#ifndef HALOADERBALANCER_HPP
#define HALOADERBALANCER_HPP

#include <string>
using namespace std;

class HeaderAnalyser_LoadBalancer {
private:

public:
    void connectInstance();
    
    void newRequest(string headers, string messageId);
};

#endif // HALOADERBALANCER_HPP