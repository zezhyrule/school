NOTES 2017/02/06

## Logical Operations

Binary representation can be used for truth representation.

AND - both conditions need to be true. 
OR - only one condition has to be true.
XOR - only one can be true.

0 is false and 1 is true.

Examples:

`
0010 1111
0100 0110
AND
0000 0110


0010 1111
0100 0110
OR
0110 1111


0010 1111
0100 0110
XOR
0110 1001
`

Bitwise operations in C use these symbols:

AND - &
OR  - |
NOT - !
XOR - ^

##Arithmetic Shift

Arithmetic Shift Left (ASL)
Each bit in the cells shift one space to the left. Rightmost cell is set
to 0.

Arithmetic Shift Right (ASR)
Each bit in the cells shift one space to the right. Leftmost cell is set
to a duplicate of what was already there.

Examples:

`
1101 1001
ASL
1011 0010

N: 1, Z: 0, V: 0, C: 1


0001 1110
ASL
0011 1100

N: 0, Z: 0, V: 0, C: 0


0101 1011
ASL
1011 0110

N: 1, Z: 0, V: 1, C: 0  // went from positive to negative, so overflow
`

If you shift a binary number to the left, the result is twice the number.
Just like with the other arithmetic, this can cause overflow. For
unsigned, check C bit, and signed, check V bit.

Shifting to the right divides the number by 2. The leftmost bit remains
unchanged. It is impossible to overflow.

`
0101 0111
ASR
0010 1011

C: 1
`

Shift in C code uses these symbols:

Left shift: `<< x`
Right shift `>> x`

Where x is the number of shifts.

##Rotation Operators

Doesn't interpret binary as integers, and only uses C flag.

Left (ROL) or right (ROR). ROL takes the most significant bit and stores
it in C, and whatever was in C becomes the least significant bit. It's the
exact opposite for ROR.

##Hexadecimal Notation

Computers understand binary, so why should we use hexadecimal? Let's look
at the number 87:

Bin: 0101 0111
Hex: 57

Hexadecimal is more condensed than binary, so it's easier for humans to
read.
