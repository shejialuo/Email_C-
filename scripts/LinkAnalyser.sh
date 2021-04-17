#! /bin/bash

sudo docker container create --network linkanalyser \
        --name $1 link_analyser
sudo docker network connect laloadbalancer $1
sudo docker network connect maloadbalancer $1

sudo docker container start $1