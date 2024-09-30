#!/bin/bash

# $chmod u+x load
# ls -l load

function build_folder() {
    cd ./build/
    echo "to build folder"
}

function cmakes() {
    cd build
    cmake ..
    echo "to cmake"
}

function build() {
    cd ./build/
    cmake --build .
    echo "to build"
}

function install() {
    cd ./build/
    cmake --install .
    echo "to install"
}

function all() {
    cd build
    cmake ..
    cmake --build .
    ./1.test --random
    # ./2.test --random
}
# --help=random
#  ./1.test --random

case "$1" in
    folder)
        build_folder
        ;;
    cmake)
        cmakes
        ;;
    build)
        build
        ;;
    install)
        install
        ;;
    all)
        all
        ;;
esac