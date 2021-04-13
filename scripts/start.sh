#! /bin/bash

# startLoadBalancer() {
#     sudo docker start mploadbalancer
#     sudo docker start haloadbalancer
#     sudo docker start laloadbalancer
#     sudo docker start taloadbalancer
#     sudo docker start saloadbalancer
#     sudo docker start vsloadbalancer
#     sudo docker start amloadbalancer
#     sudo docker start ialoadbalancer
#     sudo docker start ndloadbalancer
#     sudo docker start irloadbalancer
#     sudo docker start maloadbalancer
# }

# startLoadBalancer


# # #* 每一个负载均衡运行实例，运行数为一个

# sudo docker container create --network messageparser \
#     --name messageparser1 messageparser
# sudo docker network connect maloadbalancer messageparser1
# sudo docker network connect haloadbalancer messageparser1
# sudo docker network connect laloadbalancer messageparser1
# sudo docker network connect taloadbalancer messageparser1
# sudo docker network connect vsloadbalancer messageparser1
# sudo docker network connect database messageparser1
# sudo docker network connect mploadbalancer messageparser1 

# sudo docker container create --network headeranalyser \
#     --name headeranalyser1 headeranalyser
# sudo docker network connect haloadbalancer headeranalyser1
# sudo docker network connect maloadbalancer headeranalyser1

# sudo docker container create --network linkanalyser \
#     --name linkanalyser1 linkanalyser
# sudo docker network connect laloadbalancer linkanalyser1
# sudo docker network connect maloadbalancer linkanalyser1

# sudo docker container create --network textanalyser \
#     --name textanalyser1 textanalyser
# sudo docker network connect taloadbalancer textanalyser1
# sudo docker network connect maloadbalancer textanalyser1
# sudo docker network connect saloadbalancer textanalyser1

# sudo docker container create --network sentimentanalyser \
#     --name sentimentanalyser1 sentimentanalyser
# sudo docker network connect saloadbalancer sentimentanalyser1
# sudo docker network connect textanalyser sentimentanalyser1

# sudo docker container create --network virusscanner \
#     --name virusscanner1 virusscanner
# sudo docker network connect vsloadbalancer virusscanner1
# sudo docker network connect maloadbalancer virusscanner1
# sudo docker network connect amloadbalancer virusscanner1

# sudo docker container create --network attachmentmanager \
#     --name attachmentmanager1 attachmentmanager
# sudo docker network connect amloadbalancer attachmentmanager1
# sudo docker network connect ialoadbalancer attachmentmanager1

# sudo docker container create --network imageanalyser \
#     --name imageanalyser1 imageanalyser
# sudo docker network connect ialoadbalancer imageanalyser1
# sudo docker network connect ndloadbalancer imageanalyser1
# sudo docker network connect irloadbalancer imageanalyser1
# sudo docker network connect maloadbalancer imageanalyser1

# sudo docker container create --network nsfwdetector \
#     --name nsfwdetector1 nsfwdetector
# sudo docker network connect ndloadbalancer nsfwdetector1
# sudo docker network connect imageanalyser nsfwdetector1

# sudo docker container create --network imagerecognizer \
#     --name imagerecognizer1 imagerecognizer
# sudo docker network connect irloadbalancer imagerecognizer1
# sudo docker network connect imageanalyser imagerecognizer1

# sudo docker container create --network messageanalyser \
#     --name messageanalyser1 messageanalyser
# sudo docker network connect database messageanalyser1

# sudo docker container create --network messagereceiver \
#     --name messagereceiver --ip 192.168.81.110 messagereceiver
# sudo docker network connect mailgenerator messagereceiver
# sudo docker network connect mploadbalancer messagereceiver

# sudo docker container create --network database \
#     --name database --ip 192.168.104.110 database
# sudo docker network connect messageparser database
# sudo docker network connect messageanalyser database

# sudo docker container crate --network mailgenerator \
#     --name mailgenerator --ip 192.168.80.110 mailgenerator
# sudo docker network connect messagereceiver mailgenerator

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

