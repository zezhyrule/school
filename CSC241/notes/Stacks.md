NOTES - 10/06/2016

Prefix and Postfix verification in paper notes.

Chapter 7

##Stacks

Specifications of an ADT for a particular problem can emerge during the design
of the problem's solution. Examples (in book): readAndCorrect algorithm and
displayBackward algorithm.

Stack Abstraction

Stacks of trays - when you take a tray from a stack, you remove the one on the
top first. Last in, first out.

Terminology:
* top - the entry point into the stack
* LIFO - last in, first out
* push - adding something to a stack; gets added to the top
* pop - removing the top element of a stack

Remember, *all* activity occurs at the top of the stack.

Abstract Data Type Stack (from slides)

A stack of elements of type T is a finite sequence of elements of T, together
with the following operations:
1. Create the stack, leaving it empty
2. Test whether the stack is Empty
3. Push a new entry onto the top of the stack, provided the stack isn't full
4. Pop the entry off the top of the stack, provived it's not empty
5. Retrieve the Peek entry from the stack, provived it's not empty

ADT Stack _page 354_ (from book)

Structure: all elements of the same type
Operations:
* create an empty stack
* determine if empty
* add a new item to the stack
* remove from the stack the item that was added most recently
* remove all items from the stack
* retrieve from the stack the item that was added most recently

A program can use a stack independetly of the stack's implementation.

##Examples of Stack

Example: Postfix Calculations

Problem: Replace 2 elements in a stack with their sum

Postfix Expression: `34+`


AddTop(OneE1)

replace the top 2 elements of a nonempty stack of numbers with their sum. If
it's only one number, leave stack unchanged

Pre: stack is nonempty stack of numbers
Post: stack is a nonempty stack of numbers, where the top element is the sum of
the top 2 elements on the original stack. OneEl is a boolean variable that
becomes true when the stack has only one element initially.

Algorithm:

`
operand2 = pop() - called op2 because it matters with - and /
if isEmpty() then
	oneEl = TRUE
	push(operand2)
else
	oneEl = FALSE
	operand1 = pop()
	push(operand1+operand2)
`


Another example:

Problem: Sum the numbers in a stack

AddStack()

Procedure to replace the elemnts of a nonempty stack of numbers with their sum

Pre: stack is nonempty stack of numbers
Post: stack

Algorithm:

`
repeat the following
	AddTop(OneEl)
until OneEl is TRUE
`

A Final Example:

Problem: print the elements of a stack from bottom to top

PrintStackUp()

Procedure to print the elements of a stack from bottom to top, leaving the stack
unchanged.

Pre: stack exists
Post: elements of the stack are printed from bottom to top. Stack unchanged.

Algorithm:

`
if not isEmpty() then
	element = pop()
	PrintStackUp()
	write element
	push(element)
`

##Applications of Stacks

Recognizing Strings in a Language

Language L

L = {w$w' : w is a possible empty string of characters other than $,
		w' = reverse(w)}
	
Examples of strings in this language:
* a25$52a
* abc$cba

A stack can be used to determine whether a given string is in L. Traverse the
first half of the string, pushing each character onto a stack. Once you reach
the $, for each character in the second half of the string, pop a character off
the stack. Match the popped character with the current character in the string.


Algebraic Expressions

When the ADT stack is used to solve a problem, the use of the ADT's operations
should not depend on its implementation. To evaluate an infix expression,
convert the infx expression to postfix form,then evaluate the postfix expression.

Evaluating a Postfix Expression:

The string is syntatically correct postfix expression. No unary operators are
present. No exponentiation operators are present. Operands are single lowercase
letters.


For each token in the string:
	if (token is an operand)
		push value that token represents onto a stack
	else //if not an operand, token is an operator (op)
		op2 = pop() //righthand side
		op1 = pop()
		result = op1 op op2
		push(result)


##Converting Infix Expressions to Equivalent Postfix

Facts about conversion:
* Operands always stay in the same order with respect to one another
* An operator will move only "to the right" with respect to the operands
* All parentheses are removed

_page 378_ has an algorithm for this conversion. 

Dr. Dunn also has an algorithm:

In-Stack Priority Table (ISP)


)	undefined
^   3
*,/ 2
+,- 1
(   0

In-Coming Priority (ICP)

)	undefined
^	4
*,/ 2
+,- 1
(   4


Scan the infix expression from left to right. For each token, perform the
following:

1. If token is an operand then append to postfix string.

2. Else if token is ), then pop all tokens off the stack and append them to
postfix string, down to the (. Pop the ( from the stack.

3. Else token is operator or open parentheses, while ISP >= ICP, pop a token and
append it to the postfix string. (Remember the stack may be empty). When ISP <
ICP, push the token on the stack.

When the end of the infix expression is reached, check the stack. If it's empty,
done; otherwise, pop tokens from the stack and append to the postfix string.

Homework 4 has eight problems. Get started on first six.
