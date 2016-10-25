NOTES - 10/04/16

Next exam is over 6, 7, 8, and 9.

##Recursion as Problem-Solving Technique

Recall that a grammar may be recursive - 

<identifier> = <letter> 
				| <identifier><letter> 
				| <identifier><number>
Some Examples of recursive grammar:

`
isID(in w:string):boolean
//returns true if w is a legal identifier
if (w is of length 1)
	if (w is a letter)
		return true
	else
		return false
else if (the last character of w is a letter or a digit)
	return isID(w minus its last character)
else
	return false
`

Trace the above code with AB, 2, A2*

##Palindromes

Some palindromes:
mom
radar
deed - even number of letters

w is a palindrome iff the first and last character of w are the same and w minus
its first and last characters is a palindrome. 
Two base cases: after stripping away pairs, the empty string remains
				after stripping away pairs, a single character remains

`
isPal(in w:string):boolean
//returns true if w is a palindrome
if (w is the empty string or w is of length 1)
	return true
else if (w's first and last characters are the same letter)
	return isPal(w minus its first and last characters)
else
	return false
`

Trace the above code with deed, radar

##Strings of the form A^nB^n

String consists of n consecutive As followed by n consecutive Bs.
Base case: after stripping away pairs, the empty string remains.

`
if(the length of w is zero)
	return true
else if(w begins with the character A and ends with the character B)
	return isAB(?)
else
	return false
`

##Algebraic Expressions

a+b - infix expression
+ab - prefix expression
ab+ - postfix expression

Prefix and postfix expressions never need precedence rules, association rules,
or parentheses. They have simple grammar expressions and straightforward
recognition and evaluation algorithms.

Prefix Grammar
prefix expression = <identifier> | <operator> < prefix ex >  < prefix ex >
operatior = + | - | * | /
identifier = a | b | ... | z

`
isPre()
	size = length of expression strExp
	lastChar = endPre(0, size-1)
	if (lastChar >= 0 and lastChar == size-1)
		return true
	else
		return false
`

Trace the above code with the expression +a/-*bc+def (go left to right)

Postfix Grammar
postfix expression = < identifier> | < postfix ex >  < postfix ex > <operator>
operatior = + | - | * | /
identifier = a | b | ... | z

`
isPost()
	if (exp is a single letter)
		return exp
	else
		return postfix(prefix1) + postfix(prefix2) + operation
`

Trace the above code with the expression ab+c* (go right to left)
Try abc*+def/gh-*

To avoid ambiguity, infix notation requires fully-parenthesized expressions.

Summary

Backtracting is a solutions strategy that involves both recursion and a sequence
of guesses that ultimately lead to a solution. A grammar is a device for
defining a language. A language is a set of strings and symbols. Different
languages of algebraic expressions have their relative advantages and
disadvantages (prefix, postfix, infix). A close relationship exists between
mathematical induction and recursion.
