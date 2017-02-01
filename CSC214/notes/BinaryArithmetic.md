NOTES - 2017/02/01

##Binary Example

As established, the number of bits can only be stored in the size of the
blocks. A block storing a byte can only store 8 bits. It is possible for
two number to be 8 bits long but the sum go beyond the blocks. The CPU
contains a single bit storage called the carry bit. This is the store the
carryover from addition.

These two numbers fit within a byte of memory, but adding them together
creates overflow, which sets the carry bit high. This is used to allow the
new value from the sum to be temporarily used.

1101 0000
0100 1101
+
0001 1101 C: 1

## Negative Integers

Unsigned binary only works for nonnegative integers. If we wish to
represent -5 in binary, we can't simply place a negative sign in front of
it (can't use a symbol other than 0 or 1).

Signed numbers use the most significant bit to denote whether the number
is positive or negative. This changes the range of possible numbers.

We could just use the leftmost bit as a positive or negative sign, leaving
the other numbers the same, but this can make math difficult.

The way negative numbers are stored needs to be slightly different to
facilitate arithmetic. 

## Additive Inverse

Using the additive inverse allows us to find the two's complement, which
is how negative numbers are represented in signed integers.

Two find the two's complement, first we start by finding the One's
Complement of the number. This is done by taking the original number and
flipping all the bits (also known as the NOT operation). If you add this
flipped number to the original, the number is still off. You need to add 1
to this to get the desired result.

See: 5 + -5

0000 0101 "5
1111 1010 "NOT 5
+
1111 1111 "One's complement
0000 0001 "add 1
+
0000 0000 " 5-5=0

Two's Complement is know as Negation (NEG). Find the one's complement of
the positive equivalent, then add 1 to this value.

Example: NEG 0000 0101 = 1111 1011

More formally: NEG x = 1 + NOT x


##Range of Two's Complement

For unsigned integers we can compute the range starting at 0 and going
through all ones:

0000 0000 -> 1111 1111

000 -> 256

For signed numbers, computing the range is slightly different. Using a
four bit number to make it easier to think about, the max positive number
is 7. Positive range in 4bit goes from 0000 -> 0111. 

Negative numbers work a little differently. We know that 1001 = -7 from
two's complement. Our negative range will go from 1000 -> 1111.

If +1 = 0001, then NEG 0001 = 1111. Subtracting 1 from this number we get
1110 which gives us 1110 (-2). Keep subtracting and we get to 1001, which
we saw was -7 from earlier. Subtracting one more gives us 1000 (-8).

In 4 bits, -8 has a peculiar property. NEG 1000 = 1000. This means
positive 8 cannot be represented in a 4bit signed integer. In 8 bits, 
the range will be -128 -> 127.

##Base Conversions

The convert from (signed) decimal to binary is a two step process. Convert
its magnitude from decimal to binary as unsigned. If the original number
was positive, you're done here. If the decimal number was negative, 
perform negative by taking two's complement.
