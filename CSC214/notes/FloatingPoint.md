NOTES - 2017/02/08

##Another Way To Convert Bases

6702
/10 R: 2
670
/10 R: 0
67
/10 R: 7
6
/10 R: 6

The remainders show the original number

50
/2  R: 0
25
/2  R: 1
12
/2  R: 0
6
/2  R: 0
3
/2  R: 1
1
/2  R: 1

50 in binary: 0011 0010

##Floating Point Numbers

It's possible to store non-integers in programs (float, double, etc.), but
how are these represented?

In decimal,

100 = 10^2
10  = 10^1
1   = 10^0
.1  = 10^-1 or 1/10
.01 = 10^-2 or 1/100

To convert floating point decimal into binary, convert the whole number
part normally, and then mirror the process for the fractional part.
Multiply by 2 and see if there's a number written to the 1s spot. If there
is, then you put a 1 in the spot. If not, you put a 0. Continue this.

6.5859375

turns into

0110.1001011

##Infinite Representations

Some numbers cannot be converted evenly into binary fractions (0.2). A
repeating pattern is created that goes on forever. However, we have finite
storage for our numbers. Just like 0.33... in decimal, we truncate it.

Sidebar: scientific notation works in binary too.

Decimal - 0.00234 = 2.34 x 10^-3

Binary  - 1101011 = 1.101 x 2^6

This is referred to as Normalized Notation.

##Mantissa

The significand of the number in normalized form is the portion multiplied
to the base to a certain power. 1.345 x 10^5 - "1.345" is the mantissa

##Excess Representation

You have to bias numbers to represent them for floating points.

A different way of representing negative numbers is with excess. The
excess or biasness gives us a different range of numbers for positive and
negative. The relation is to half the range (rounded down).

4-bits: 16 values in signed -8 to 7

Biased range is 0 to 15. The excess is the max range divided by 2.

Excess for 4bit is 7. Subtract this excess from the biased (positive)
range to get unbiased (negative) numbers.

Ex. For 5bits, the biased range is 0-31. The excess is 15. Unbiased range
is -15 to 16

##Putting it all Together

Floating point numbers are stored as a normalized number. 1 bit for the
sign, 8 bits for the exponent, and 23 bits for the mantissa in a 32bit
floating point number.

We have a bit for the sign and bits for the numbers. There's no bit to
represent the decimal place, however. It's unnecessary, and by virtue of
making the number normalized, we know the format will be "1.whatever".

Since we know tho format to normalized numbers we assume a 1 leads the
decimal place. Thus, we don't need to store it.

Example:

11-bit memory cell

1 bit for the sign, 4 for the exponent, and 6 for the mantissa.

Store the number -15.16 = 1111.00101

Normalize the number : 1.11100101 x 2^3

Bias the exponent:

4 bits to store exponent means excess is 7. Biasing 3 gives us 10. In
binary, this is 1010.

Get the Mantissa:

1.11100101

Drop the leading 1 and the point.

11100101

Only six bits to represent it, so truncate it.

111001

So the complete floating point number -15.16 in 4bit binary is:

11010111001
