#!/bin/bash
set -v
printf \\n\\n\\n
cat p4.sh
printf \\f
cat -b p4.java
cat -b p4StackA.java
cat -b p4StackP.java
cat -b p4StackInterface.java
:
:
:
javac p4.java
java p4
:
:
:
date
