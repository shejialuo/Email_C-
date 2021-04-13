#! /bin/bash

#* 首先每个负载均衡器需要首先运行。
#* 本测试中负载均衡数量均为一个，不调度。

sudo docker create --network mploadbalancer  \
    --ip 192.168.82.110 --name mploadbalancer mploadbalancer
sudo docker network connect messagereceiver mploadbalancer 
sudo docker network connect messageparser mploadbalancer 

sudo docker create --network haloadbalancer  \
    --ip 192.168.84.110 --name haloadbalancer haloadbalancer
sudo docker network connect headeranalyser haloadbalancer 
sudo docker network connect messageparser haloadbalancer 

sudo docker create --network laloadbalancer  \
    --ip 192.168.86.110 --name laloadbalancer laloadbalancer
sudo docker network connect linkanalyser laloadbalancer 
sudo docker network connect messageparser laloadbalancer 

sudo docker create --network taloadbalancer  \
    --ip 192.168.88.110 --name taloadbalancer taloadbalancer
sudo docker network connect textanalyser taloadbalancer 
sudo docker network connect messageparser taloadbalancer 

sudo docker create --network saloadbalancer  \
    --ip 192.168.90.110 --name saloadbalancer saloadbalancer
sudo docker network connect sentimentanalyser saloadbalancer 
sudo docker network connect textanalyser saloadbalancer 

sudo docker create --network vsloadbalancer  \
    --ip 192.168.92.110 --name vsloadbalancer vsloadbalancer
sudo docker network connect virusscanner vsloadbalancer 
sudo docker network connect messageparser vsloadbalancer

sudo docker create --network amloadbalancer  \
    --ip 192.168.94.110 --name amloadbalancer amloadbalancer
sudo docker network connect attachmentmanager amloadbalancer 
sudo docker network connect virusscanner amloadbalancer 

sudo docker create --network ialoadbalancer  \
    --ip 192.168.96.110 --name ialoadbalancer ialoadbalancer
sudo docker network connect imageanalyser ialoadbalancer 
sudo docker network connect attachmentmanager ialoadbalancer

sudo docker create --network ndloadbalancer  \
    --ip 192.168.98.110 --name ndloadbalancer ndloadbalancer
sudo docker network connect nsfwdetector ndloadbalancer
sudo docker network connect imageanalyser ndloadbalancer 

sudo docker create --network irloadbalancer  \
    --ip 192.168.100.110 --name irloadbalancer irloadbalancer
sudo docker network connect imagerecognizer irloadbalancer
sudo docker network connect imageanalyser irloadbalancer 

sudo docker create --network maloadbalancer  \
    --ip 192.168.102.110 --name maloadbalancer maloadbalancer
sudo docker network connect messageanalyser maloadbalancer
sudo docker network connect headeranalyser maloadbalancer
sudo docker network connect linkanalyser maloadbalancer 
sudo docker network connect textanalyser maloadbalancer 
sudo docker network connect imageanalyser maloadbalancer
sudo docker network connect virusscanner maloadbalancer