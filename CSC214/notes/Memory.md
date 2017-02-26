NOTES - 2017/02/20

##Main Memory

All programs run in main memory. The structure of memory allows us to know
how to pull program instructions. Each memory cell is one byte for this
machine and there are 65,536 locations from 0x0000 to 0xFFFF

The memory address with the small address is referred to as the top of
memory. The memory addresses with large addresses are referred to the
bottom of memory.


Words are a way of organizing bytes of memory together. Pep/9 one word is
2 contiguous bytes. One word is 16-bits. Word sizes correspond to the data
a CPU handles. Pep/9 most registers are 16-bits long able to hold 1 word.

When stored in memory, we get the location of the starting place. If a
word uses memory space 0x000A and 0x000B, the word's location is 0x000A.

Since everything we deal with concerns bytes, it is important not to
confuse location with content. Values stored in the memory and the
location of the memory both are represented with a series of bits.


##Interpreting Bytes

We can see bytes in different ways. It could be read as a two's complement
integer (721) or an ASCII value ('Q').

Pep/9 simulates having input and output devices plugged in. Two modes of
I/O, interactive: input comes from keyboard and printed to screen, or
batch: simulates info coming in from file. The machine needs to store the
info for the I/O devices. In our machine, 0xFC15 is input and 0xFC16 is
output.

##Data and Control

The data can flow between the modules by going through the CPU. Data from
input travels through the bus into the CPU. Data can then flow from CPU to
memory, DISK, or output.

Control lines are signals the CPU makes to other parts of the hardware. To
move data from input to memory, the CPU must send a signal to memory.

##Instruction Format

_pg. 190_

Instructions are a set of bytes that tells the processor to perform a
specific function. Each processor has its own specific set of
instructions. This is why compiled code needs to be compiled on specific
machines. Pep/9 has 40 instructions in its set.

Each instruction consists of a single byte called the instruction
specifier. Some instructions also include another word called the operand
specifier. Instructions with just the instruction specifier are called
unary instructions.

##Instruction Specifier

The first part of the instruction is called the operation code or opcode
(consisting of anywhere from 4 to 8 bits). Some opcodes can have varying
bits to determine extra actions. Denote the bits with n, r, a. These are
still 1 or 0, but the letter corresponds to a different set of
instructions.

aaa is addressing mode. This determines how to read contents of memory.
r is register, 0 being the accumulator A, or 1 being the index register X.
Accumulator is data storage, and index register stores an address.

##Addressing Mode

Pep/9 executes nonunary instructions in 8 different addressing modes. Two
important ones are direct (the data you need exists in a specific
location) and indirect (the data you need exists in random locations, but
locations are stored in a specific place).

##Translating Machine Language

The CPU translates the instruction and pulls data from memory.

Example:

At location 01A3 - 0111 1101 

Subtract is 0111 raaa

Opcode is 0111 (SUB)
Register field is 1 (index)
Addressing field is 101 (indexed)

We know it's non-unary due to the instruction needing addressing (aaa).
This means that the word following it will be the inputs.

Operand Specifier: 
At location 01A4 - 0000 0011
At location 01A5 - 0100 1110
