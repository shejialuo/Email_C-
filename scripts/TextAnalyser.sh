#! /bin/bash

sudo docker container create --network textanalyser \
        --name $1 text_analyser
sudo docker network connect taloadbalancer $1
sudo docker network connect maloadbalancer $1
sudo docker network connect saloadbalancer $1

sudo docker container start $1