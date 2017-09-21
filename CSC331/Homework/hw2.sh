#!/bin/bash
# Homework 2
# Charles Davis
# Shell script to compile and run hw2 program.
g++ -std=c++11 hw2.cpp -o hw2
hw2 $1
