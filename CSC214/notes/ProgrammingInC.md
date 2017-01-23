NOTES - 2017/01/23

##printf

Use specifiers in the first parameter of printf and scanf functions to
specify where variables of a certain type go in a string.
%d for integers, %f for floats, etc.

##Order of Functions

Since functions in C are not tied to a class, the order in which you put
functions matters. If you try to call a function before it's defined, the
program doesn't know what to do and won't compile. 

You can fix this by declaring a function prototype at the top of the file
that tells the compiler that a function exists with a certain return type
and parameters, so then it will expect it.

The compiler still compiles linearly, but it now knows how to deal with
the function call syntactically. 

##Global and Constants

Global variables can be accessed and changed by any function under the
scope at which the variable is declared.

Constants are declared by using the keyword 'const' before the data type.
By convention, make the variable name capital.

##Reference

Why use the &? This says we are asking for the reference to the variable
(the memory location).

##Primitives

Objects don't exist in C, so all data types are really primitives. These
primitives contain char, short, int, long, float, double, long double,
bool, void and wchar_t (wide char for Unicode) as well as unsigned 
versions of many of these.

##Integers and Floating Point Numbers

Storing a floating point number as an integer will truncate the decimal
(without rounding). Integers can be stored in floating points (a .0 is
added to the number).

##Characters

Chars are integers with special encoding. Any source code can use
characters as integers. var = 65 could represent the integer 65 or the
ASCII letter 'A'.

##Arrays and Strings

Grouping of contiguous space that holds a group of similar elements (ints,
doubles, characters). Memory must be allocated at compile time (static
memory). Size is static and must be declared in code.

Syntax: Type name [number of elements]

Example: int myarray[5];
		 myarray[0] = 1;
		 myarray[1] = 2;
		 etc..

You can also initialize an array like: int myarray[] = {1,2};

Since arrays are static you have to know the size beforehand. Usually when
making arrays we declare a constant that will be used for our size. The
constant can be used later to have the size.

Strings in C are simply character arrays. The array contains a number of
characters and ends with the null symbol "\0". This is null-termination.
It lets the compiler know where the string ends in the array.

`
char hello[] = {'H', 'e', 'l', 'l', 'o', '\0'};

or

char hello[] = "Hello";
`
