#!/bin/bash

START_FOLDER=$(pwd)

apt-get update
apt-get install -y sudo

sudo apt-get install -y clang
sudo DEBIAN_FRONTEND=noninteractive apt-get install -y cmake
sudo apt-get install -y libboost-all-dev

sudo apt-get install -y libgtest-dev
cd /usr/src/gtest
sudo cmake .
sudo make
cd "$START_FOLDER"
