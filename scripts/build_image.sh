#! /bin/bash

MailGenerator(){
    cd ~/Projects/Email_Microservices/MailGenerator
}

MessageReceiver(){
    cd ~/Projects/Email_Microservices/MessageReceiver
}

MessageParser_LoadBalancer(){
    cd ~/Projects/Email_Microservices/MessageParser/load_balancer
}

MessageParser(){
    cd ~/Projects/Email_Microservices/MessageParser/main
}

HeaderAnalyser_LoadBalancer(){
    cd ~/Projects/Email_Microservices/HeaderAnalyser/load_balancer
}

HeaderAnalyser(){
    cd ~/Projects/Email_Microservices/HeaderAnalyser/main
}

LinkAnalyser_LoadBalancer(){
    cd ~/Projects/Email_Microservices/LinkAnalyser/load_balancer
}

LinkAnalyser(){
    cd ~/Projects/Email_Microservices/LinkAnalyser/main
}

TextAnalyser_LoadBalancer(){
    cd ~/Projects/Email_Microservices/TextAnalyser/load_balancer
}

TextAnalyser(){
    cd ~/Projects/Email_Microservices/TextAnalyser/main
}

SentimentAnalyser_LoadBalancer(){
    cd ~/Projects/Email_Microservices/TextAnalyser/SentimentAnalyser/load_balancer
}

SentimentAnalyser(){
    cd ~/Projects/Email_Microservices/TextAnalyser/SentimentAnalyser/main
}

VirusScanner_LoadBalancer(){
    cd ~/Projects/Email_Microservices/AttachmentAnalysis/VirusScanner/load_balancer
}


VirusScanner(){
    cd ~/Projects/Email_Microservices/AttachmentAnalysis/VirusScanner/main
}

AttachmentManager_LoadBalancer(){
    cd ~/Projects/Email_Microservices/AttachmentAnalysis/AttachmentManager/load_balancer
}

AttachmentManager(){
    cd ~/Projects/Email_Microservices/AttachmentAnalysis/AttachmentManager/main
}

ImageAnalyser_LoadBalancer(){
    cd ~/Projects/Email_Microservices/AttachmentAnalysis/ImageAnalyser/load_balancer
}

ImageAnalyser(){
    cd ~/Projects/Email_Microservices/AttachmentAnalysis/ImageAnalyser/main
}

NSFWDetector_LoadBalancer(){
    cd ~/Projects/Email_Microservices/AttachmentAnalysis/ImageAnalyser/NSFWDetector/load_balancer
}

NSFWDetector(){
    cd ~/Projects/Email_Microservices/AttachmentAnalysis/ImageAnalyser/NSFWDetector/main
}

ImageRecognizer_LoadBalancer(){
    cd ~/Projects/Email_Microservices/AttachmentAnalysis/ImageAnalyser/ImageRecognizer/load_balancer
}

ImageRecognizer(){
    cd ~/Projects/Email_Microservices/AttachmentAnalysis/ImageAnalyser/ImageRecognizer/main
}

MessageAnalyser_LoadBalancer(){
    cd ~/Projects/Email_Microservices/MessageAnalyser/load_balancer
}

MessageAnalyser(){
    cd ~/Projects/Email_Microservices/MessageAnalyser/main
}

DataBase(){
    cd ~/Projects/Email_Microservices/DataBase
}

BuildImage(){
    sudo docker build -t $1 .
}

All(){
    MailGenerator
    BuildImage "mail_generator"
    MessageReceiver
    BuildImage "message_receiver"
    MessageParser_LoadBalancer
    BuildImage "mp_loadbalancer"
    MessageParser
    BuildImage "message_parser"
    HeaderAnalyser_LoadBalancer
    BuildImage "ha_loadbalancer"
    HeaderAnalyser
    BuildImage "header_analyser"
    LinkAnalyser_LoadBalancer
    BuildImage "la_loadbalancer"
    LinkAnalyser
    BuildImage "link_analyser"
    TextAnalyser_LoadBalancer
    BuildImage "ta_loadbalancer"
    TextAnalyser
    BuildImage "text_analyser"
    SentimentAnalyser_LoadBalancer
    BuildImage "sa_loadbalancer"
    SentimentAnalyser
    BuildImage "sentiment_analyser"
    VirusScanner_LoadBalancer
    BuildImage "vs_loadbalancer"
    VirusScanner
    BuildImage "virus_scanner"
    AttachmentManager_LoadBalancer
    BuildImage "am_loadbalancer"
    AttachmentManager
    BuildImage "attachment_manager"
    ImageAnalyser_LoadBalancer
    BuildImage "ia_loadbalancer"
    ImageAnalyser
    BuildImage "image_analyser"
    NSFWDetector_LoadBalancer
    BuildImage "nd_loadbalancer"
    NSFWDetector
    BuildImage "nsfw_detector"
    ImageRecognizer_LoadBalancer
    BuildImage "ir_loadbalancer"
    ImageRecognizer
    BuildImage "image_recognizer"
    MessageAnalyser_LoadBalancer
    BuildImage "ma_loadbalancer"
    MessageAnalyser
    BuildImage "message_analyser"
    DataBase
    BuildImage "database"
}

main(){
    if [ "$1" = "ALL" ]; then
        All
    elif [ "$1" = "mail_generator" ]; then
        MailGenerator
        BuildImage $1
    elif [ "$1" = "message_receiver" ]; then
        MessageReceiver
        BuildImage $1
    elif [ "$1" = "mp_loadbalancer" ]; then
        MessageParser_LoadBalancer
        BuildImage $1
    elif [ "$1" = "message_parser" ]; then
        MessageParser
        BuildImage $1
    elif [ "$1" = "ha_loadbalancer" ]; then
        HeaderAnalyser_LoadBalancer
        BuildImage $1
    elif [ "$1" = "header_analyser" ]; then
        HeaderAnalyser
        BuildImage $1
    elif [ "$1" = "la_loadbalancer" ]; then
        LinkAnalyser_LoadBalancer
        BuildImage $1
    elif [ "$1" = "link_analyser" ]; then
        LinkAnalyser
        BuildImage $1
    elif [ "$1" = "ta_loadbalancer" ]; then
        TextAnalyser_LoadBalancer
        BuildImage $1
    elif [ "$1" = "text_analyser" ]; then
        TextAnalyser
        BuildImage $1
    elif [ "$1" = "sa_loadbalancer" ]; then
        SentimentAnalyser_LoadBalancer
        BuildImage $1
    elif [ "$1" = "sentiment_analyser" ]; then
        SentimentAnalyser
        BuildImage $1
    elif [ "$1" = "vs_loadbalancer" ]; then
        VirusScanner_LoadBalancer
        BuildImage $1
    elif [ "$1" = "virus_scanner" ]; then
        VirusScanner
        BuildImage $1
    elif [ "$1" = "am_loadbalancer" ]; then
        AttachmentManager_LoadBalancer
        BuildImage $1
    elif [ "$1" = "attachment_manager" ]; then
        AttachmentManager
        BuildImage $1
    elif [ "$1" = "ia_loadbalancer" ]; then
        ImageAnalyser_LoadBalancer
        BuildImage $1
    elif [ "$1" = "image_analyser" ]; then
        ImageAnalyser
        BuildImage $1
    elif [ "$1" = "nd_loadbalancer" ]; then
        NSFWDetector_LoadBalancer
        BuildImage $1
    elif [ "$1" = "nsfw_detector" ]; then
        NSFWDetector
        BuildImage $1
    elif [ "$1" = "ir_loadbalancer" ]; then
        ImageRecognizer_LoadBalancer
        BuildImage $1
    elif [ "$1" = "image_recognizer" ]; then
        ImageRecognizer
        BuildImage $1
    elif [ "$1" = "ma_loadbalancer" ]; then
        MALoadBalancer
        BuildImage $1
    elif [ "$1" = "message_analyser" ]; then
        MessageAnalyser
        BuildImage $1
    elif [ "$1" = "database" ]; then
        DataBase
        BuildImage $1
    else
        echo "ERROR"
    fi
}

main $1