#! /bin/bash

#* 首先每个负载均衡器需要首先运行。
#* 本测试中负载均衡数量均为一个，不调度。

MessageParser_LoadBalancer(){
    sudo docker container rm mploadbalancer
}

HeaderAnalyser_LoadBalancer(){
    sudo docker container rm haloadbalancer
}

LinkAnalyser_LoadBalancer(){
    sudo docker container rm laloadbalancer
}

TextAnalyser_LoadBalancer(){
    sudo docker container rm taloadbalancer
}
 
SentimentAnalyser_LoadBalancer(){
    sudo docker container rm saloadbalancer
}

VirusScanner_LoadBalancer(){
    sudo docker container rm vsloadbalancer
}

AttachmentManager_LoadBalancer(){
    sudo docker container rm amloadbalancer
}

ImageAnalyser_LoadBalancer(){
    sudo docker container rm ialoadbalancer
}

NSFWDetector_LoadBalancer(){
    sudo docker container rm ndloadbalancer
}
 
ImageRecognizer_LoadBalancer(){
    sudo docker container rm irloadbalancer
}

MessageAnalyser_LoadBalancer(){
    sudo docker container rm maloadbalancer
}

All(){
    MessageParser_LoadBalancer
    HeaderAnalyser_LoadBalancer
    LinkAnalyser_LoadBalancer
    TextAnalyser_LoadBalancer
    SentimentAnalyser_LoadBalancer
    VirusScanner_LoadBalancer
    AttachmentManager_LoadBalancer
    ImageAnalyser_LoadBalancer
    NSFWDetector_LoadBalancer
    MessageAnalyser_LoadBalancer
    ImageRecognizer_LoadBalancer
}

main(){
    if [ "$1" = "ALL" ]; then
        All
    elif [ "$1" = "MPLoadBalancer" ]; then
        MessageParser_LoadBalancer
    elif [ "$1" = "HALoadBalancer" ]; then
        HeaderAnalyser_LoadBalancer
    elif [ "$1" = "LALoadBlancer" ]; then
        LinkAnalyser_LoadBalancer
    elif [ "$1" = "TALoadBalancer" ]; then
        TextAnalyser_LoadBalancer
    elif [ "$1" = "SALoadBalancer" ]; then
        SentimentAnalyser_LoadBalancer
    elif [ "$1" = "VSLoadBalancer" ]; then
        VirusScanner_LoadBalancer
    elif [ "$1" = "AMLoadBalancer" ]; then
        AttachmentManager_LoadBalancer
    elif [ "$1" = "IALoadBalancer" ]; then
        ImageAnalyser_LoadBalancer
    elif [ "$1" = "NDLoadBalancer" ]; then
        NSFWDetector_LoadBalancer
    elif [ "$1" = "IRLoadBalancer" ]; then
        ImageRecognizer_LoadBalancer
    elif [ "$1" = "MALoadBalancer" ]; then
        MessageAnalyser_LoadBalancer
    else
        echo "ERROR"
    fi
}

main $1