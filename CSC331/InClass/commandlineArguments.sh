#!/bin/bash
g++ -std=c++11 commandlineArguments.cpp -o commandlineArguments
commandlineArguments $1
