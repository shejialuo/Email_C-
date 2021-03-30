#! /bin/bash

cd ~/Projects/Email_Microservices/AttachmentAnalysis/\
VirusScanner/load_balancer

g++ -g ./main.cpp ./VSLoadBalancer.cpp ../../../Lib/Server.cpp \
../../../Lib/Client.cpp -o main