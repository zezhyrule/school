NOTES - 2017/02/06

##Signed Binary to Decimal

Check the first bit: if it's 0, then do a normal binary-decimal
conversion. If it's a 1, then the number is negative and there are two
options to convert it to decimal. Either convert back to positive with
two's complement or do a direct conversion. Two's complement is probably
the easier method, however.

Two's Complement in Reverse:

`
1101 1010
NOT
0010 0101
ADD 1
0010 0110
`

Convert to decimal: 38
Make it negative: -38


##Number Overflow

With unsigned integers we can detect if the SUM of two numbers is out of
range. If we go out of range, then a special bit called the carry bit is
set. For signed numbers the carry bit is not used for this. We need
another way to determine if signed numbers go out of range.

CPU has another bit to determine signed overflow, in a register called V.
Using this, we can perform binary addition like normal, and if the C bit
has a different state from the value carried into the leftmost bit, we set
the overflow (v) bit to 1. 

EXAMPLES:

Let's add 47 and 70 together. (sum is 117)

`
0010 1111
0100 0110
+
0111 0101

C: 0 
V: 0
`

Now let's try:
101 + 32 = 133

`
0110 0101
0010 0000
+
1000 0101

C: 0
V: 1
`

C bit and number carried to most significant bit are different, so there
was an overflow (range max is 127). The V bit is set high to indicate
this overflow.

`
1100 0110
1011 1100
+
1000 0010

C: 1
V: 0
`

In this case, there was no overflow, but the carry bit was set.

Some assumptions can be made: if two numbers are added that are the same
sign and result in a different sign, we have overflow. Also, adding
numbers of opposite signs cannot result in overflow.

##Negative and Zero Bits

In addition to the C and V bits, the CPU also keeps two more bits for
computation. N-bit is set if the result of an operation is negative. The
Z-bit is set of the result of an operation is all 0.
