#!/bin/bash

cd ~/Projects/Email_Microservices/MessageReceiver
g++ -g ./MessageReceiver.cpp ./main.cpp ../Lib/Client.cpp ../Lib/Server.cpp -o MessageReceiver