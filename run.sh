#!/bin/bash

echo $1

if [[ $1 = gg ]]
then
    echo "not reb"
    cp ./build/compile_commands.json ./compile_commands.json 
    cmake --build build
    ./build/ogl
fi

if [[ $1  = f  || $2 = f ]]
then
    echo "rebuilding"
    rm -r build
    cmake -S./ -B build -DCMAKE_BUILD_TYPE=Debug -G "Ninja" 

    cmake --build build
    cp ./build/compile_commands.json ./compile_commands.json 
    ./build/ogl

fi

if [[ $1 = git ]]
then
    git add .
    git commit -m "test"
    git push
fi

if [[ $1 = copy ]]
then
    sudo ../copy.sh
fi
