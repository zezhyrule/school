NOTES - 2017/02/13

##4-bit Excess Range

We know that we get an excess range of 7 with 4-bits. We get the negative
(unbiased) numbers by subtracting 7 from our (biased) positive range.

The biased notation is thus obtained by adding 7 to the unbiased number.

-7 : 0000
-6 : 0001
.
.
.
0  : 0111
1  : 1000
2  : 1001
.
.
.

The excess range is used for the exponent. 

*Example:*

pg. 22 field notes

Go backwards!

1 01110 011010
  exp^  ^mantissa

Sign is negative

Actual mantissa is 1.011010

Normalized is 1.011010 x 2^?

Exponent is 01110. In five bits, bias is from 00000 to 11111 (0-31)
Excess is max/2, which mean the excess is 15.

Subtract 15 from biased number (14)

14 - 15 = -1

-1 is exponent.

Take number out of normalized form:

0.1011010

Convert to decimal:

1/2 + 1/8 + 1/16 + 1/64 = .703125

And make sure it's negative!

Answer: -0.703125


##Rounding

Most of the time we cannot fit the entire mantissa into the cells. There
must be a truncation. Round to the nearest number, and if there's a tie,
round to the even number.

Table Example:

|Decimal|Rounded|Binary  |Rounded|
|-------|-------|--------|-------|
|23.499 |  23   |1011.011| 1011  |
|23.5   |  24   |1011.1  | 1100  |
|23.501 |  24   |1011.101| 1100  |
|24.499 |  24   |1100.011| 1100  |
|24.5   |  24   |1100.1  | 1100  |
|24.501 |  25   |1100.101| 1101  |


If the next space is a zero, it always rounds down.

*Example 2:*

|Sign|Exponent|Mantissa|
|----|--------|--------|
|0   |001     |0000    |

Excess = 3

1.0000 x 2^-2

|Sign|Exponent|Mantissa|
|----|--------|--------|
|0   |000     |0000    |

1.0000 x 2^-3

##How to store a 0?

A special case is set aside for zero. If every bit in the exponent field
is 0 and every bit in the mantissa field is 0, this is interpreted as a 0.

However, this means some precision is lost. Smallest possible value in
8bits is 0 000 0001 which is 0.1328125 and the largest is 0 111 1111 which
is 31.0. For negative, just invert the signs giving a range of -31 to
-0.1328125.

If a number falls outside the range of these values, this causes either
overflow (going beyond the range toward +-infinity) or underflow
(in between 0 and the smallest number +-.1328125).

##Infinity

We denote infinity by having all bits in the exponent be 1 and all
mantissa bits be 0. Infinity is used to handle operations which would
cause overflow. Examples: 3/inf = 0 and 5 + inf = inf
If computing with real numbers, you get an infinity, then overflow has
occurred.

##Not a Number

NaN is used to denote floating point numbers which are illegal, such as
the sqrt of a negative or 0/0. Any operation which has at least one NaN
produces a NaN. The exponent is all 1s, and the mantissa is Non-Zero.


##Special Cases Table

|Exp|Mantissa|Value|
|---|--------|-----|
|000|0000    |  0  |
|111|0000    | inf |
|111|non-zero| NaN |
