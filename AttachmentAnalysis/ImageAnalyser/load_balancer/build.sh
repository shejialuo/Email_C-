#!/bin/bash

cd ~/Projects/Email_Microservices/AttachmentAnalysis/ImageAnalyser/load_balancer
g++ -g ./main.cpp ./IALoadBalancer.cpp ../../../Lib/Server.cpp ../../../Lib/Client.cpp -o IALoadBalancer