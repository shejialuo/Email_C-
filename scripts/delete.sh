#! /bin/bash

fileName=$(ls /home/shejialuo/Projects/Email_Microservices/Executable)

fileNameBefore=Executable

for file in $fileName
do
    fileLowercase=$file
    typeset -l fileLowercase
    sudo docker image rm -f $fileLowercase
    sudo docker container rm -f "$fileLowercase"1
done