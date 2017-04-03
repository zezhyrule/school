NOTES - 2017/04/03

##Combinational Circuits

A circuit is a collection of devices physically connected with wires.
There are two types - combinational and sequential. 

In combinational circuits, the input determines the output. Each line
carries a signal (voltage). Computationally, 1 means voltage is present
and 0 means no voltage is present.

A combinational circuit is like a black box in which a certain number
of inputs are translated to a predictable output (stateless).

Truth tables are an expression of the boolean value associated with a
certain expression. Boolean algebra expressions are boolean expressions
presented algebraically. A logic diagram is a model or mockup of the
traversal of the input into output.

## Boolean Algebra

An algebraic expression written according to Boolean laws. Such an
expression describes how a combinational circuit works. Similar to
standard algebra but with a few differences. 

* Binary OR: +
* Binary AND: *
* Unary Complement: '


*Ten Properties of Boolean Algebra:*

|Property|OR|AND|
|--------|--|---|
|Commutative|x + y = y + x| x * y = y * x|
|Associative|(x+y)+z = x + (y+z)|(x*y) * z = x * (y*z)|
|Distributive|x + (y*z) = (x+y) * (x+z)|x * (y+z) = (x*y)+(x*z)|
|Identity|x + 0 = x |x * 1 = x|
|Complement|x + (x') = 1|x * (x') = 0|

Boolean algebra has some properties in addition to these basic ones:
The distributive property works for both + and *, unlike in regular
algebra. The associative property allows us to simplify expressions by
removing parentheses from these groups.

Due to the binary nature of Boolean algebra, the laws have a symmetry
to them that standard algebraic laws do not have. This is known as the
duality property. Looking at the original 10 properties, we can see
there's really just 5 but swapping AND for OR and 1 for 0, and vice
versa.

*Order of Precedence:*

Parentheses are first, then Complement, then AND, then OR.

We can derive other properties by using our original laws of Boolean
algebra. We can prove that new expressions are equivalent to 1 or more
of the previously defined laws

For example, proving the Idempotent Property: applying an operation to
itself will yield itself as a result. (x * x = x; x + x = x)

Prove x + x = x

= (x+x)*1
= (x+x)*(x+x')
= x + (x*x')
= x + 0
= x

Prove x * x = x

= (x*x)+0
= (x*x)+(x*x')
= x * (x+x')
= x * 1
= x

Notice the Duality Property in play here. You can use duality to assert
a theorem. You can flip the operation and values, and this has been
shown to give other corresponding theorems. As a rule, you are allowed
to use any other proven rule or axiom in a current proof.

*Zero Theorem:* x + 1 = 1; x * 0 = 0

Proof x + 1 = 1

= x + x + x'
= x + x'
= 1

Or another way (not using idempotent):

= (x*1) + 1
= (1+x) * 1
= (1+x) * (x+x')
= x + (1*x')
= x + x'
= 1

*Absorption Property:*

So called because the y value is absorbed into the x value.

x + x * y = x; x * (x + y) = x

Prove x + x * y = x

= (x*1)+(x*y)
= x * (1 + y)
= x * 1
= x
