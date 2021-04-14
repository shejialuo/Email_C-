#! /bin/bash

#* 首先每个负载均衡器需要首先运行。
#* 本测试中负载均衡数量均为一个，不调度。

MessageParser_LoadBalancer(){
    sudo docker create --network mploadbalancer  \
        --ip 192.168.82.110 --name mploadbalancer mp_loadbalancer
    sudo docker network connect messagereceiver mploadbalancer
    sudo docker network connect messageparser mploadbalancer

}

HeaderAnalyser_LoadBalancer(){
    sudo docker create --network haloadbalancer  \
        --ip 192.168.84.110 --name haloadbalancer ha_loadbalancer
    sudo docker network connect headeranalyser haloadbalancer
    sudo docker network connect messageparser haloadbalancer
}

LinkAnalyser_LoadBalancer(){
    sudo docker create --network laloadbalancer  \
        --ip 192.168.86.110 --name laloadbalancer la_loadbalancer
    sudo docker network connect linkanalyser laloadbalancer
    sudo docker network connect messageparser laloadbalancer
}

TextAnalyser_LoadBalancer(){
    sudo docker create --network taloadbalancer  \
        --ip 192.168.88.110 --name taloadbalancer ta_loadbalancer
    sudo docker network connect textanalyser taloadbalancer
    sudo docker network connect messageparser taloadbalancer
}
 
SentimentAnalyser_LoadBalancer(){
    sudo docker create --network saloadbalancer  \
        --ip 192.168.90.110 --name saloadbalancer sa_loadbalancer
    sudo docker network connect sentimentanalyser saloadbalancer 
    sudo docker network connect textanalyser saloadbalancer 
}

VirusScanner_LoadBalancer(){
    sudo docker create --network vsloadbalancer  \
        --ip 192.168.92.110 --name vsloadbalancer vs_loadbalancer
    sudo docker network connect virusscanner vsloadbalancer
    sudo docker network connect messageparser vsloadbalancer
}

AttachmentManager_LoadBalancer(){
    sudo docker create --network amloadbalancer  \
        --ip 192.168.94.110 --name amloadbalancer am_loadbalancer
    sudo docker network connect attachmentmanager amloadbalancer 
    sudo docker network connect virusscanner amloadbalancer 
}

ImageAnalyser_LoadBalancer(){
    sudo docker create --network ialoadbalancer  \
        --ip 192.168.96.110 --name ialoadbalancer ia_loadbalancer
    sudo docker network connect imageanalyser ialoadbalancer
    sudo docker network connect attachmentmanager ialoadbalancer
}

NSFWDetector_LoadBalancer(){
    sudo docker create --network ndloadbalancer  \
        --ip 192.168.98.110 --name ndloadbalancer nd_loadbalancer
    sudo docker network connect nsfwdetector ndloadbalancer
    sudo docker network connect imageanalyser ndloadbalancer
}
 
ImageRecognizer_LoadBalancer(){
    sudo docker create --network irloadbalancer  \
        --ip 192.168.100.110 --name irloadbalancer ir_loadbalancer
    sudo docker network connect imagerecognizer irloadbalancer
    sudo docker network connect imageanalyser irloadbalancer
}

MessageAnalyser_LoadBalancer(){
    sudo docker create --network maloadbalancer  \
        --ip 192.168.102.110 --name maloadbalancer ma_loadbalancer
    sudo docker network connect messageanalyser maloadbalancer
    sudo docker network connect headeranalyser maloadbalancer
    sudo docker network connect linkanalyser maloadbalancer
    sudo docker network connect textanalyser maloadbalancer
    sudo docker network connect imageanalyser maloadbalancer
    sudo docker network connect virusscanner maloadbalancer
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