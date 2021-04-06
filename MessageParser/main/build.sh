#!/bin/bash

cd ~/Projects/Email_Microservices/MessageParser/main
g++ -g ./MessageParser.cpp ./main.cpp ../../Lib/Server.cpp ../../Lib/Client.cpp -o MessageParser