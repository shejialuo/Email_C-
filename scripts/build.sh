#! /bin/bash

ExecutableDirectory=~/Projects/Email_Microservices/Executable

#* MailGenerator
cd ~/Projects/Email_Microservices/MailGenerator 
g++ -g ./MailGenerator.cpp ./main.cpp ../Lib/Client.cpp -o $ExecutableDirectory/MailGenerator

#* MessageReceiver
cd ~/Projects/Email_Microservices/MessageReceiver
g++ -g ./MessageReceiver.cpp ./main.cpp ../Lib/Client.cpp ../Lib/Server.cpp -o $ExecutableDirectory/MessageReceiver

#* MessageParser_LoadBalancer
cd ~/Projects/Email_Microservices/MessageParser/load_balancer
g++ -g ./MPLoadBalancer.cpp ./main.cpp ../../Lib/Server.cpp ../../Lib/Client.cpp -o $ExecutableDirectory/MPLoadBalancer

#* MessageParser
cd ~/Projects/Email_Microservices/MessageParser/main
g++ -g ./MessageParser.cpp ./main.cpp ../../Lib/Server.cpp ../../Lib/Client.cpp -o $ExecutableDirectory/MessageParser -lpthread

#* HeaderAnalyser_LoadBalancer
cd ~/Projects/Email_Microservices/HeaderAnalyser/load_balancer
g++ -g ./main.cpp ./HALoadBalancer.cpp ../../Lib/Server.cpp ../../Lib/Client.cpp -o $ExecutableDirectory/HALoadBalancer

#* HeaderAnalyser
cd ~/Projects/Email_Microservices/HeaderAnalyser/main
g++ -g ./main.cpp ./HeaderAnalyser.cpp ../../Lib/Server.cpp ../../Lib/Client.cpp -o $ExecutableDirectory/HeaderAnalyser

#* LinkAnalyser_LoadBalancer
cd ~/Projects/Email_Microservices/LinkAnalyser/load_balancer
g++ -g ./main.cpp ./LALoadBalancer.cpp ../../Lib/Server.cpp ../../Lib/Client.cpp -o $ExecutableDirectory/LALoadBalancer

#* LinkAnalyser
cd ~/Projects/Email_Microservices/LinkAnalyser/main
g++ -g ./main.cpp ./LinkAnalyser.cpp ../../Lib/Server.cpp ../../Lib/Client.cpp -o $ExecutableDirectory/LinkAnalyser

#* TextAnalyser_LoadBalancer
cd ~/Projects/Email_Microservices/TextAnalyser/load_balancer
g++ -g ./main.cpp ./TALoadBalancer.cpp ../../Lib/Client.cpp ../../Lib/Server.cpp -o $ExecutableDirectory/TALoadBalancer

#* TextAnalyser
cd ~/Projects/Email_Microservices/TextAnalyser/main
g++ -g ./main.cpp ./TextAnalyser.cpp ../../Lib/Client.cpp ../../Lib/Server.cpp -o $ExecutableDirectory/TextAnalyser -lpthread

#* SentimentAnalyser_LoadBalancer
cd ~/Projects/Email_Microservices/TextAnalyser/SentimentAnalyser/load_balancer
g++ -g ./main.cpp ./SALoadBalancer.cpp ../../../Lib/Client.cpp ../../../Lib/Server.cpp -o $ExecutableDirectory/SALoadBalancer

#* SentimentAnalyser
cd ~/Projects/Email_Microservices/TextAnalyser/SentimentAnalyser/main
g++ -g ./main.cpp ./SentimentAnalyser.cpp ../../../Lib/Client.cpp ../../../Lib/Server.cpp -o $ExecutableDirectory/SentimentAnalyser

#* VirusScanner_LoadBalancer
cd ~/Projects/Email_Microservices/AttachmentAnalysis/VirusScanner/load_balancer
g++ -g ./main.cpp ./VSLoadBalancer.cpp ../../../Lib/Server.cpp ../../../Lib/Client.cpp -o $ExecutableDirectory/VSLoadBalancer

#* VirusScanner
cd ~/Projects/Email_Microservices/AttachmentAnalysis/VirusScanner/main
g++ -g ./main.cpp ./VirusScanner.cpp ../../../Lib/Server.cpp ../../../Lib/Client.cpp -o $ExecutableDirectory/VirusScanner

#* AttachmentManager_LoadBalancer
cd ~/Projects/Email_Microservices/AttachmentAnalysis/AttachmentManager/load_balancer
g++ -g ./main.cpp ./AMLoadBalancer.cpp ../../../Lib/Server.cpp ../../../Lib/Client.cpp -o $ExecutableDirectory/AMLoadBalancer

#* AttachmentManager
cd ~/Projects/Email_Microservices/AttachmentAnalysis/AttachmentManager/main
g++ -g ./main.cpp ./AttachmentManager.cpp ../../../Lib/Server.cpp ../../../Lib/Client.cpp -o $ExecutableDirectory/AttachmentManager

#* ImageAnalyser_LoadBalancer
cd ~/Projects/Email_Microservices/AttachmentAnalysis/ImageAnalyser/load_balancer
g++ -g ./main.cpp ./IALoadBalancer.cpp ../../../Lib/Server.cpp ../../../Lib/Client.cpp -o $ExecutableDirectory/IALoadBalancer

#* ImageAnalyser
cd ~/Projects/Email_Microservices/AttachmentAnalysis/ImageAnalyser/main
g++ -g ./main.cpp ./ImageAnalyser.cpp ../../../Lib/Server.cpp ../../../Lib/Client.cpp -o $ExecutableDirectory/ImageAnalyser -lpthread

#* NSFWDetector_LoadBalancer
cd ~/Projects/Email_Microservices/AttachmentAnalysis/ImageAnalyser/NSFWDetector/load_balancer
g++ -g ./main.cpp ./NDLoadBalancer.cpp ../../../../Lib/Server.cpp ../../../../Lib/Client.cpp -o $ExecutableDirectory/NDLoadBalancer

#* NSFWDetector
cd ~/Projects/Email_Microservices/AttachmentAnalysis/ImageAnalyser/NSFWDetector/main
g++ -g ./main.cpp ./NSFWDetector.cpp ../../../../Lib/Server.cpp ../../../../Lib/Client.cpp -o $ExecutableDirectory/NSFWDetector

#* ImageRecognizer_LoadBalancer
cd ~/Projects/Email_Microservices/AttachmentAnalysis/ImageAnalyser/ImageRecognizer/load_balancer
g++ -g ./main.cpp ./IRLoadBalancer.cpp ../../../../Lib/Server.cpp ../../../../Lib/Client.cpp -o $ExecutableDirectory/IRLoadBalancer

#* ImageRecognizer
cd ~/Projects/Email_Microservices/AttachmentAnalysis/ImageAnalyser/ImageRecognizer/main
g++ -g ./main.cpp ./ImageRecognizer.cpp ../../../../Lib/Server.cpp ../../../../Lib/Client.cpp -o $ExecutableDirectory/ImageRecognizer

#* MessageAnalyser_LoadBalancer
cd ~/Projects/Email_Microservices/MessageAnalyser/load_balancer
g++ -g ./main.cpp ./MALoadBalancer.cpp ../../Lib/Server.cpp ../../Lib/Client.cpp -o $ExecutableDirectory/MALoadBalancer

#* MessageAnalyser
cd ~/Projects/Email_Microservices/MessageAnalyser/main
g++ -g ./main.cpp ./MessageAnalyser.cpp ../../Lib/Server.cpp ../../Lib/Client.cpp -o $ExecutableDirectory/MessageAnalyser -lpthread

#* Database

cd ~/Projects/Email_Microservices/DataBase
g++ -g ./main.cpp ./DataBase.cpp ../Lib/Server.cpp ../Lib/Client.cpp -o $ExecutableDirectory/DataBase