#!/bin/bash
set -v
printf \\n\\n\\n
cat p5.sh
printf \\f
cat -b p5.java
cat -b p5Queue.java
cat -b p5PriorityQueue.java
:
:
:
javac p5.java
java p5
:
:
:
date
