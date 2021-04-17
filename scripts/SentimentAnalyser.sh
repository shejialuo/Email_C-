#! /bin/bash

sudo docker container create --network sentimentanalyser \
        --name $1 sentiment_analyser
sudo docker network connect saloadbalancer $1
sudo docker network connect textanalyser $1

sudo docker container start $1