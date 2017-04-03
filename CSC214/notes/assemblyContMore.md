NOTES - 2017/03/27

##Symbols

Previously we addressed the problem of modifying code and modifying the
location data is stored. BR instruction should fix this problem
What if we modify the data we have by removing or adding. Then we have
to change where the BR jumps.

We can use symbols to refer to lines of code in assembly. Instead of
referencing memory address, we reference the symbol. The assembler can
translate the symbol to its memory location. 

Syntax:
~~~~
<name>: <instruction> <operand>, <addressing>
main: DECI 0x0003,d
~~~~

##Compilers

A compiler is similar to an assembler. The input is called the source
program and the output is the object program. The most efficient path is
to translate directly to machine language.

Translating Hello World from C into Assembly:

~~~~
int main()
{
	printf("Hello, world!\n");
	return 0;
}
~~~~

~~~~
0000 490004			STOP	msg,d
0003 00				STOP
0004 48656C msg:	.ASCII	"Hello, world!\n\x00"
	 6C6F2C
	 20776F
	 726C64
	 210A00
0013				.END
~~~~

Variables in C have 3 attributes: name, type, and value. This translates
to a memory location. 

##charOut and charIn

The memory locations for input and output:

* FC15 - input
* FC16 - output

This information is stored by the OS in location FFF8 and FFFA. What if
the OS changes the values for the location of input and output? Using
charOut and charIn will alleviate this problem. The value charOut will
always grab the location stored in FFFA even if changed.

##Global Variables

Allocation of a fixed location in memory using .BLOCK. Usually done at the
beginning of the program.

Accessed with direct addressing. No need for it to point anywhere else,
allocated before runtime. Different from local variables which are
generally allocated in the middle of program. Corresponds to other
function traces.

##Assignment Statements

In assembly you have to load into the accumulator from the right hand side
of the assignment with LDA. Compute the value of the right hand side if
necessary. Store into the lefthand side using STA.

Assembly for j += 5

~~~~
LDWA	j,d
ADDA	5,i
STWA	j,d
~~~~

##Constants and .EQUATE


