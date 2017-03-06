NOTES - 2017/03/06

##Big Endian

Our examples up to this point have been Big endian. This starts from the
top and works its way down memory. Little endian reads bottom up.

##Von Neumann Machines

The model modern machines are based on is von neumann machines. Memory
contains data and program (and in old machines, memory consisted of state
in some external storage). In 1945, he proposed storing instruction data
in memory as well.

Pep/9 is a von Neumann machine and has the following execution outlined:

`
Load the machine program into memory at address 0x0000
Initialize PC and SP:
PC < 0000
SP < FFF4
do{
	Fetch the next instruction
	PC < PC+1
	Decode the instruction specifier
	Increment PC by 2 if nonunary
	Execute the instruction fetched
}
while(the stop instruction does not execute && instructions are legal)
`

##Execution Cycle

Cycle is hardwired into CPU. Program is loaded into memory at 0x0000.
First instruction is loaded there. Next instruction is adjacent and so on.
If non-unary, the next two spots are part of the previous instruction. The
Program Counter is initialized at 0x0000 and the Stack Pointer is set to
0xFFF4. The PC holds location of the next instruction. The SP holds the
location of the top of the run-time stack.

First operation is a fetch: the CPU examines the PC and goes to that
memory location to grab the instruction.

Decode: The value is stripped apart and analyzed for opcode, register, and
addressing mode used. 

Increment the PC: We need to point to our next location so we increment
the PC (by 1 if unary, by 3 if not).

Execute: the instruction is executed with the appropriate values.

Repeat: start all over assuming that the previous instruction was not a
halt.

##Sample Execution

|Address|MachineLanguage (hex)|
|-------|---------------------|
|0000|D1000D|
|0003|F1FC16|
|0006|D1000E|
|0009|F1FC16|
|000C|00|
|000D|4869|

1. Fetch instruction from PC location
2. D1 - load byte into register A from location 000D.
3. Increment PC to 0003
4. Execute decoded command from 2: load 48 into A
5. F1 - store byte r<8..15> into memory from A into FC16
6. Increment PC to 0006
7. Store 48 into memory location FC16
8. D1 - load byte into A from 000E
9. Increment PC to 0009
10. Load 69 into A
11. Fetch F1 from PC location
12. PC incremented by 1
13. Nonunary, FC16, increment PC by 2 to 000C
14. 69 from A is stored into FC16
15. Fetch instruction from 000C - 00 (end)
16. Increment PC
17. Stop execution

##Von Neumann Bugs

Since the program shares memory with data we need to tell the program to
stop execution. If we don't have a 0000 0000 command, the PC will move to
the next instruction, which might be data. Since programs are just data,
it is possible to have programs call other programs. This is where having
program stacks come in.

##Memory Structure of Pep/9

Two types of memory: Read/Write Memory and Read-Only Memory.

Read/Write memory is also called Random-Access Memory (RAM). It's called
this because it's not serial. Can load from RAM and store to RAM.

ROMs work similarly, but you can't store memory to ROM, only load from
ROM. RAM and ROM are both random. _see: pep/9 memory structure slide_

From FB8F to the very end, this space is set aside for the operating
system. FC17 to the end is ROM. FC15 is input device, FC16 is output.
The OS uses up a small part of the memory.

0000 to FB8E is all for applications. The run-time stack starts at the end
of this memory and grows up and down as the stack changes in size.


