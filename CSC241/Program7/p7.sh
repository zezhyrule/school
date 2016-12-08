#!/bin/bash
set -v
printf \\n\\n\\n
cat p7.sh
printf \\f
cat -b p7.java
cat -b p7Edge.java
cat -b p7Graph.java
:
:
:
javac p7.java
java p7
:
:
:
date
