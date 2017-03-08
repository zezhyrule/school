NOTES 2017-03-08

##Machine Code

Machine only understands binary. Bytes correspond to a series of
instructions which are hardwired into CPU. Programming a machine is
writing the machine code.

##Compiled Languages

If machines only understand binary, why do we have compiled languages?
Compilers are able to translate the code from these languages into machine
code.

##Assembly Language

Assembly is much easier than machine code. Assembler translates
instructions into machine code. It has two components: the mnemonic which
is the instruction, and pseudo ops, which are data bit patters that tell
the assembler to do something.

Example:

`C1009A`

C1 is the load word instruction into accumulator, with direct addressing.
Translated into assembly:

`LDWA 0x009A, d`

LDWr is the load word mnemonic. A is the register we use (accumulator).
0x009A is the address to load from and d is the addressing mode.

Assembly language is line-oriented. Each instruction must be on one line.
Comments are denoted with a semicolon.

_Pseudo-Operations:_ Statements with no corresponding machine
instruction. Used to tell the assembler to perform a certain task. 

The *.ASCII* pseudo-op places strings of ascii characters into memory.

The *.END* pseudo-op tells the assembler when the program ends.

_Trap Operations:_ Fault operations, unimplemented codes. Cannot be used
directly in machine language but useful for assembly. We can set aside
certain bytes for assembly-level instructions. (NOP, no-operation trap;
STRO, string output trap, etc.).

##Hi Program in Assembly

`

(gnome-ssh-askpass:12436): Gtk-WARNING **: cannot open display:  
error: unable to read askpass response from '/usr/libexec/openssh/gnome-ssh-askpass'
;A program to output "Hi"
;
LDBA		0x000D, d	;Load byte accumulator 'H'

STBA		0xFC16, d	;Store byte accumulator output device

LDBA		0x000E, d	;Load byte accumulator 'i'

STBA		0xFC16, d	;Store byte accumulator output device

STOP					;Stop

.ASCII		"Hi"		;ASCII "Hi" characters

.END

`

Assembler output:
`D1 00 0D F1 FC 16 D1 00 0E F1 FC 16 00 48 69 zz`

Program output:
`Hi`
