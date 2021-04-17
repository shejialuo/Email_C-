#! /bin/bash

sudo docker container create --network headeranalyser \
        --name $1 header_analyser
sudo docker network connect haloadbalancer $1
sudo docker network connect maloadbalancer $1

sudo docker container start $1