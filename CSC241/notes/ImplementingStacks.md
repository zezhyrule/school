NOTES - 10/13/16

Chapter 7 

##Converting Infix to Postfix

From previous notes:

1. If token is an operand then append to postfix string.

2. Else if token is ), then pop all tokens off the stack and append them to
postfix string, down to the (. Pop the ( from the stack.

3. Else token is operator or open parentheses, while ISP >= ICP, pop a token and
append it to the postfix string. (Remember the stack may be empty). When ISP <
ICP, push the token on the stack.

When the end of the infix expression is reached, check the stack. If it's empty,
done; otherwise, pop tokens from the stack and append to the postfix string.


Example: `A + (B*C) - D`

Postfix: `ABC*+D-`


An infix expression can be evaluated by first being converted into an equivalent
postfix expression. 

Facts about conversion:
* Operands always stay in the same order with respect to one another
* An operator will move only "to the right" with respect to the operands
* All parentheses are removed

## Implementations of ADT Stack

The ADT stack can be implemented using an array, a linked list, the ADT list.
StackInterface provides a common specification for the three implementations.
StackException Used by StackInterface extents java.lang.RuntimeException.

## Array Implementation:

Arrays are easiest implementation but have fixed size

* variable top, which is the index of the top element. 
* The array of Objects, called items
* the class specification for stack is on _pg. 365-367_
* The bottom of the stack is element 0, the top at the other end.

The stack "constructor": the stack is initialized by setting the value of top.
Remember, the constructor can access the data members top and items, but not the
program using the class; thus, it is called without parameters. Top is set to
-1.

Test for an Empty Stack: If top is less than 0

Test for Full Stack: Check if top is equal to MAX_STACK - 1

Push: insertion (push) and deletion (pop) in an array implementation is at the
end of the array. Be careful of pushing to already full array.

Pop: Check if it's empty, return the value at the top of the stack and decrement
top by 1. Be careful not to pop from an empty stack.

Peek: Returns the value at the top of the stack.


## Reference-Based Implementation:

Required when the stack needs to grow and shrink dynamically.

* StackReferenceBased implements StackInterface.
* top is a reference to the head of the linked list.

Constructor: the stack is initialized by setting top to null

Test if empty: top == null

No test for full.

Push: Insertion and deletion occurs at the head of a linked list.

Pop: Returns the value at the top of stack. Store info before deleting node.

Peek: Returns the value at the top of the stack. 
