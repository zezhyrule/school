#!/bin/bash
# Homework 4
# Charles Davis
# Shell script to compile and run p4 program.
g++ -std=c++11 Dictionary.cpp p4.cpp -o p4
p4 p4.dat
