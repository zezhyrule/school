NOTES - 2017/01/30

##Binary Storage

Computer storage either has high-voltage or low-voltage. Transmitting data
transistors know you either have a signal or none. Power transmits or there
is no power. 

A Binary Digit, or a bit, is a numerical representation of this. 0 is low
and 1 is high.

Most systems have blocks 8-cells long. A byte is eight bits. Everything is
represented by bytes (numbers, characters). The computer interprets
sequences of bytes. 

##Numbers

We are used to viewing numbers in Decimal (base 10). Machines, however,
read base 2. All numbers are thus stored using binary representations. 

The base or radix represents the number of characters used to represent the
numbers. Arithmetic is the same for other bases, but we're less familiar
with thinking about numbers in binary so we convert them to decimal or hex
for our own sake.

Decimal numbers have implied zeros in them. 1024 is NOT the same as 10240,
but 1024 is the same as 01024. Preceding zeros are not significant. This is
true no matter the base we are counting. Binary numbers are expressed in
collections of four bits (a nibble), adding preceding zeros if necessary.

Decimal Place Holders

* 1 = 10^0
* 10 = 10^1
* 100 = 10^2
* 1000 = 10^3


The decimal number 7459:

* 7 x 10^3
* 4 x 10^2
* 5 x 10^1
* 9 x 10^0


Binary Place Holders

* 1 = 2^0
* 10 = 2^1
* 100 = 2^2
* 1000 = 2^3


The binary number 1001:

* 1 * 2^3
* 0 * 2^2
* 0 * 2^1
* 1 * 2^0



