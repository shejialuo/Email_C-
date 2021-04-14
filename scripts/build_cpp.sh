#! /bin/bash

MailGenerator(){
    cd ~/Projects/Email_Microservices/MailGenerator 
    g++ -g ./MailGenerator.cpp ./main.cpp ../Lib/Client.cpp -o ./MailGenerator
}

MessageReceiver(){
    cd ~/Projects/Email_Microservices/MessageReceiver
    g++ -g ./MessageReceiver.cpp ./main.cpp ../Lib/Client.cpp ../Lib/Server.cpp -o ./MessageReceiver
}

MessageParser_LoadBalancer(){
    cd ~/Projects/Email_Microservices/MessageParser/load_balancer
    g++ -g ./MPLoadBalancer.cpp ./main.cpp ../../Lib/Server.cpp ../../Lib/Client.cpp -o ./MPLoadBalancer
}

MessageParser(){
    cd ~/Projects/Email_Microservices/MessageParser/main
    g++ -g ./MessageParser.cpp ./main.cpp ../../Lib/Server.cpp ../../Lib/Client.cpp -o ./MessageParser -lpthread
}

HeaderAnalyser_LoadBalancer(){
    cd ~/Projects/Email_Microservices/HeaderAnalyser/load_balancer
    g++ -g ./main.cpp ./HALoadBalancer.cpp ../../Lib/Server.cpp ../../Lib/Client.cpp -o ./HALoadBalancer
}

HeaderAnalyser(){
    cd ~/Projects/Email_Microservices/HeaderAnalyser/main
    g++ -g ./main.cpp ./HeaderAnalyser.cpp ../../Lib/Server.cpp ../../Lib/Client.cpp -o ./HeaderAnalyser
}

LinkAnalyser_LoadBalancer(){
    cd ~/Projects/Email_Microservices/LinkAnalyser/load_balancer
    g++ -g ./main.cpp ./LALoadBalancer.cpp ../../Lib/Server.cpp ../../Lib/Client.cpp -o ./LALoadBalancer
}

LinkAnalyser(){
    cd ~/Projects/Email_Microservices/LinkAnalyser/main
    g++ -g ./main.cpp ./LinkAnalyser.cpp ../../Lib/Server.cpp ../../Lib/Client.cpp -o ./LinkAnalyser
}

TextAnalyser_LoadBalancer(){
    cd ~/Projects/Email_Microservices/TextAnalyser/load_balancer
    g++ -g ./main.cpp ./TALoadBalancer.cpp ../../Lib/Client.cpp ../../Lib/Server.cpp -o ./TALoadBalancer
}

TextAnalyser(){
    cd ~/Projects/Email_Microservices/TextAnalyser/main
    g++ -g ./main.cpp ./TextAnalyser.cpp ../../Lib/Client.cpp ../../Lib/Server.cpp -o ./TextAnalyser -lpthread
}

SentimentAnalyser_LoadBalancer(){
    cd ~/Projects/Email_Microservices/TextAnalyser/SentimentAnalyser/load_balancer
    g++ -g ./main.cpp ./SALoadBalancer.cpp ../../../Lib/Client.cpp ../../../Lib/Server.cpp -o ./SALoadBalancer
}

SentimentAnalyser(){
    cd ~/Projects/Email_Microservices/TextAnalyser/SentimentAnalyser/main
    g++ -g ./main.cpp ./SentimentAnalyser.cpp ../../../Lib/Client.cpp ../../../Lib/Server.cpp -o ./SentimentAnalyser
}

VirusScanner_LoadBalancer(){
    cd ~/Projects/Email_Microservices/AttachmentAnalysis/VirusScanner/load_balancer
    g++ -g ./main.cpp ./VSLoadBalancer.cpp ../../../Lib/Server.cpp ../../../Lib/Client.cpp -o ./VSLoadBalancer
}


VirusScanner(){
    cd ~/Projects/Email_Microservices/AttachmentAnalysis/VirusScanner/main
    g++ -g ./main.cpp ./VirusScanner.cpp ../../../Lib/Server.cpp ../../../Lib/Client.cpp -o ./VirusScanner
}

AttachmentManager_LoadBalancer(){
    cd ~/Projects/Email_Microservices/AttachmentAnalysis/AttachmentManager/load_balancer
    g++ -g ./main.cpp ./AMLoadBalancer.cpp ../../../Lib/Server.cpp ../../../Lib/Client.cpp -o ./AMLoadBalancer
}

AttachmentManager(){
    cd ~/Projects/Email_Microservices/AttachmentAnalysis/AttachmentManager/main
    g++ -g ./main.cpp ./AttachmentManager.cpp ../../../Lib/Server.cpp ../../../Lib/Client.cpp -o ./AttachmentManager
}

ImageAnalyser_LoadBalancer(){
    cd ~/Projects/Email_Microservices/AttachmentAnalysis/ImageAnalyser/load_balancer
    g++ -g ./main.cpp ./IALoadBalancer.cpp ../../../Lib/Server.cpp ../../../Lib/Client.cpp -o ./IALoadBalancer
}

ImageAnalyser(){
    cd ~/Projects/Email_Microservices/AttachmentAnalysis/ImageAnalyser/main
    g++ -g ./main.cpp ./ImageAnalyser.cpp ../../../Lib/Server.cpp ../../../Lib/Client.cpp -o ./ImageAnalyser -lpthread
}

NSFWDetector_LoadBalancer(){
    cd ~/Projects/Email_Microservices/AttachmentAnalysis/ImageAnalyser/NSFWDetector/load_balancer
    g++ -g ./main.cpp ./NDLoadBalancer.cpp ../../../../Lib/Server.cpp ../../../../Lib/Client.cpp -o ./NDLoadBalancer
}

NSFWDetector(){
    cd ~/Projects/Email_Microservices/AttachmentAnalysis/ImageAnalyser/NSFWDetector/main
    g++ -g ./main.cpp ./NSFWDetector.cpp ../../../../Lib/Server.cpp ../../../../Lib/Client.cpp -o ./NSFWDetector
}

ImageRecognizer_LoadBalancer(){
    cd ~/Projects/Email_Microservices/AttachmentAnalysis/ImageAnalyser/ImageRecognizer/load_balancer
    g++ -g ./main.cpp ./IRLoadBalancer.cpp ../../../../Lib/Server.cpp ../../../../Lib/Client.cpp -o ./IRLoadBalancer
}

ImageRecognizer(){
    cd ~/Projects/Email_Microservices/AttachmentAnalysis/ImageAnalyser/ImageRecognizer/main
    g++ -g ./main.cpp ./ImageRecognizer.cpp ../../../../Lib/Server.cpp ../../../../Lib/Client.cpp -o ./ImageRecognizer
}

MessageAnalyser_LoadBalancer(){
    cd ~/Projects/Email_Microservices/MessageAnalyser/load_balancer
    g++ -g ./main.cpp ./MALoadBalancer.cpp ../../Lib/Server.cpp ../../Lib/Client.cpp -o ./MALoadBalancer
}

MessageAnalyser(){
    cd ~/Projects/Email_Microservices/MessageAnalyser/main
    g++ -g ./main.cpp ./MessageAnalyser.cpp ../../Lib/Server.cpp ../../Lib/Client.cpp -o ./MessageAnalyser -lpthread
}

DataBase(){
    cd ~/Projects/Email_Microservices/DataBase
    g++ -g ./main.cpp ./DataBase.cpp ../Lib/Server.cpp ../Lib/Client.cpp -o ./DataBase
}

All(){
    MailGenerator
    MessageReceiver
    MessageParser_LoadBalancer
    MessageParser
    HeaderAnalyser_LoadBalancer
    HeaderAnalyser
    LinkAnalyser_LoadBalancer
    LinkAnalyser
    TextAnalyser_LoadBalancer
    TextAnalyser
    SentimentAnalyser_LoadBalancer
    SentimentAnalyser
    VirusScanner_LoadBalancer
    VirusScanner
    AttachmentManager_LoadBalancer
    AttachmentManager
    ImageAnalyser_LoadBalancer
    ImageAnalyser
    NSFWDetector_LoadBalancer
    NSFWDetector
    ImageRecognizer_LoadBalancer
    ImageRecognizer
    MessageAnalyser_LoadBalancer
    MessageAnalyser
    DataBase
}

main(){
    if [ "$1" = "ALL" ]; then
        All
    elif [ "$1" = "MailGenerator" ]; then
        MailGenerator
    elif [ "$1" = "MessageReceiver" ]; then
        MessageReceiver
    elif [ "$1" = "MPLoadBalancer" ]; then
        MessageParser_LoadBalancer
    elif [ "$1" = "MessageParser" ]; then
        MessageParser
    elif [ "$1" = "HALoadBalancer" ]; then
        HeaderAnalyser_LoadBalancer
    elif [ "$1" = "HeaderAnalyser" ]; then
        HeaderAnalyser
    elif [ "$1" = "LALoadBlancer" ]; then
        LinkAnalyser_LoadBalancer
    elif [ "$1" = "LinkAnalyser" ]; then
        LinkAnalyser
    elif [ "$1" = "TALoadBalancer" ]; then
        TextAnalyser_LoadBalancer
    elif [ "$1" = "TextAnalyser" ]; then
        TextAnalyser
    elif [ "$1" = "SALoadBalancer" ]; then
        SentimentAnalyser_LoadBalancer
    elif [ "$1" = "SentimentAnalyser" ]; then
        SentimentAnalyser
    elif [ "$1" = "VSLoadBalancer" ]; then
        VirusScanner_LoadBalancer
    elif [ "$1" = "VirusScanner" ]; then
        VirusScanner
    elif [ "$1" = "AMLoadBalancer" ]; then
        AttachmentManager_LoadBalancer
    elif [ "$1" = "AttachmentManager" ]; then
        AttachmentManager
    elif [ "$1" = "IALoadBalancer" ]; then
        ImageAnalyser_LoadBalancer
    elif [ "$1" = "ImageAnalyser" ]; then
        ImageAnalyser
    elif [ "$1" = "NDLoadBalancer" ]; then
        NSFWDetector_LoadBalancer
    elif [ "$1" = "NSFWDetector" ]; then
        NSFWDetector
    elif [ "$1" = "IRLoadBalancer" ]; then
        ImageRecognizer_LoadBalancer
    elif [ "$1" = "ImageRecognizer" ]; then
        ImageRecognizer
    elif [ "$1" = "MALoadBalancer" ]; then
        MessageAnalyser_LoadBalancer
    elif [ "$1" = "MessageAnalyser" ]; then
        MessageAnalyser
    elif [ "$1" = "DataBase" ]; then
        DataBase
    else
        echo "ERROR"
    fi
}

main $1