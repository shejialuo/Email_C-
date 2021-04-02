#!/bin/bash

cd ~/Projects/Email_Microservices/MessageParser/load_balancer
g++ -g ./MPLoadBalancer.cpp ./main.cpp ../../Lib/Server.cpp ../../Lib/Client.cpp -o MPLoadBalancer