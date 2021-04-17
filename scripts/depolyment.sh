#! /bin/bash

MessageParser(){
    sudo docker container create --network messageparser \
        --name $1 message_parser
    sudo docker network connect maloadbalancer $1
    sudo docker network connect haloadbalancer $1
    sudo docker network connect laloadbalancer $1
    sudo docker network connect taloadbalancer $1
    sudo docker network connect vsloadbalancer $1
    sudo docker network connect database $1
    sudo docker network connect mploadbalancer $1 
}

HeaderAnalyser(){
    sudo docker container create --network headeranalyser \
        --name $1 header_analyser
    sudo docker network connect haloadbalancer $1
    sudo docker network connect maloadbalancer $1
}

LinkAnalyser(){
    sudo docker container create --network linkanalyser \
        --name $1 link_analyser
    sudo docker network connect laloadbalancer $1
    sudo docker network connect maloadbalancer $1
}

TextAnalyser(){
    sudo docker container create --network textanalyser \
        --name $1 text_analyser
    sudo docker network connect taloadbalancer $1
    sudo docker network connect maloadbalancer $1
    sudo docker network connect saloadbalancer $1
}

SentimentAnalyser(){
    sudo docker container create --network sentimentanalyser \
        --name $1 sentiment_analyser
    sudo docker network connect saloadbalancer $1
    sudo docker network connect textanalyser $1
}

VirusScanner(){
    sudo docker container create --network virusscanner \
        --name $1 virus_scanner
    sudo docker network connect vsloadbalancer $1
    sudo docker network connect maloadbalancer $1
    sudo docker network connect amloadbalancer $1
}

AttachmentManager(){
    sudo docker container create --network attachmentmanager \
        --name $1 attachment_manager
    sudo docker network connect amloadbalancer $1
    sudo docker network connect ialoadbalancer $1
}

ImageAnalyser(){
    sudo docker container create --network imageanalyser \
        --name $1 image_analyser
    sudo docker network connect ialoadbalancer $1
    sudo docker network connect ndloadbalancer $1
    sudo docker network connect irloadbalancer $1
    sudo docker network connect maloadbalancer $1
}

NSFWDetector(){
    sudo docker container create --network nsfwdetector \
        --name $1 nsfw_detector
    sudo docker network connect ndloadbalancer $1
    sudo docker network connect imageanalyser $1
}

ImageRecognizer(){
    sudo docker container create --network imagerecognizer \
        --name $1 image_recognizer
    sudo docker network connect irloadbalancer $1
    sudo docker network connect imageanalyser $1
}

MessageAnalyser(){
    sudo docker container create --network messageanalyser \
        --name $1 message_analyser
    sudo docker network connect database $1
    sudo docker network connect maloadbalancer $1
}

DataBase(){
    sudo docker container create --network database \
        --name database --ip 192.168.104.110 database
    sudo docker network connect messageparser database
    sudo docker network connect messageanalyser database
}

MessageReceiver(){
    sudo docker container create --network messagereceiver \
        --name messagereceiver --ip 192.168.81.110 message_receiver
    sudo docker network connect mailgenerator messagereceiver
    sudo docker network connect mploadbalancer messagereceiver
}

MailGenerator(){
    sudo docker container create --network mailgenerator \
        --name mailgenerator --ip 192.168.80.110 mail_generator
    sudo docker network connect messagereceiver mailgenerator
}

ContainerBuild(){
    MessageParser "messageparser1"
    HeaderAnalyser "headeranalyser1"
    LinkAnalyser "linkanalyser1"
    TextAnalyser "textanalyser1"
    SentimentAnalyser "sentimentanalyser1"
    VirusScanner "virusscanner1"
    AttachmentManager "attachmentmanager1"
    ImageAnalyser "imageanalyser1"
    NSFWDetector "nsfwdetector1"
    ImageRecognizer "imagerecognizer1"
    MessageAnalyser "messageanalyser1"
    DataBase
    MessageReceiver
    MailGenerator
}

main(){
    sudo docker container start mploadbalancer
    sudo docker container start haloadbalancer
    sudo docker container start laloadbalancer
    sudo docker container start taloadbalancer
    sudo docker container start saloadbalancer
    sudo docker container start vsloadbalancer
    sudo docker container start amloadbalancer
    sudo docker container start ialoadbalancer
    sudo docker container start ndloadbalancer
    sudo docker container start irloadbalancer
    sudo docker container start maloadbalancer
    sudo docker container start messageparser1
    sudo docker container start headeranalyser1
    sudo docker container start linkanalyser1
    sudo docker container start textanalyser1
    sudo docker container start sentimentanalyser1
    sudo docker container start virusscanner1
    sudo docker container start attachmentmanager1
    sudo docker container start imageanalyser1
    sudo docker container start nsfwdetector1
    sudo docker container start imagerecognizer1
    sudo docker container start messageanalyser1
    sudo docker container start messagereceiver
    sudo docker container start database
    sudo docker container start mailgenerator
}



ContainerBuild
main
