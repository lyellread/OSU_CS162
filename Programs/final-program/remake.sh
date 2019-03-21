#!/bin/bash

clear 
make clean 
make
make remove_ofiles
./escape maze.txt
