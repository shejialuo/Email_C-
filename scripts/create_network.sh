#! /bin/bash

sudo docker network create --subnet=192.168.80.0/24 mailgenerator

sudo docker network create --subnet=192.168.81.0/24 messagereceiver

sudo docker network create --subnet=192.168.82.0/24 mploadbalancer
sudo docker network create --subnet=192.168.83.0/24 messageparser

sudo docker network create --subnet=192.168.84.0/24 haloadbalancer
sudo docker network create --subnet=192.168.85.0/24 headeranalyser

sudo docker network create --subnet=192.168.86.0/24 laloadbalancer
sudo docker network create --subnet=192.168.87.0/24 linkanalyser

sudo docker network create --subnet=192.168.88.0/24 taloadbalancer
sudo docker network create --subnet=192.168.89.0/24 textanalyser
sudo docker network create --subnet=192.168.90.0/24 saloadbalancer
sudo docker network create --subnet=192.168.91.0/24 sentimentanalyser

sudo docker network create --subnet=192.168.92.0/24 vsloadbalancer
sudo docker network create --subnet=192.168.93.0/24 virusscanner
sudo docker network create --subnet=192.168.94.0/24 amloadbalancer
sudo docker network create --subnet=192.168.95.0/24 attachmentmanager
sudo docker network create --subnet=192.168.96.0/24 ialoadbalancer
sudo docker network create --subnet=192.168.97.0/24 imageanalyser
sudo docker network create --subnet=192.168.98.0/24 ndloadbalancer
sudo docker network create --subnet=192.168.99.0/24 nsfwdetector
sudo docker network create --subnet=192.168.100.0/24 irloadbalancer
sudo docker network create --subnet=192.168.101.0/24 imagerecognizer

sudo docker network create --subnet=192.168.102.0/24 maloadbalancer
sudo docker network create --subnet=192.168.103.0/24 messageanalyser

sudo docker network create --subnet=192.168.104.0/24 database