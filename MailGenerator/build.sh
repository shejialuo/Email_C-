#!/bin/bash

cd ~/Projects/Email_Microservices/MailGenerator 
g++ -g ./MailGenerator.cpp ./main.cpp ../Lib/Client.cpp -o MailGenerator