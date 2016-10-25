NOTES - 10/20/16

Chapter 9

##Inheritance

Inheritance - OOP enables one class to inherit the data and function members
from another. Promotes reuse of code. A method for one class can be used again
in a class that inherits. We can add new members in the new class. We can also
reprogram a method from a parent class if you need it edited in the child class.

Using the Sphere class "../oldAssignments/Sphere.java" from earlier, a ball
class may be defined as a subclass.

The derived class inherits all members (except constructors). The derived class
may make changes such as adding its own data members, adding member functions,
and revising inherited member functions (must keep same parameter declarations
and same return type). It cannot revise private data members of ancestors or
reuse names.

A derived class cannot access the private members of the base class directly.
Inheritance does not mean access. The constructors for the derived class invoke
the constructors for the base class. Methods of a subclass can call the
superclass's public methods. Clients of a derived class may invoke the public
members of the base class. For an overridden method, instances of the subclass
will use the new method. Instances of the superclass will use the original
method. (known as static binding or early binding)

Diagrams on _pg. 462-463_

Membership categories of a class:
* Public members can be used by anyone. Members declared without an access
	modifier are available to methods of the class or within the package.
* Private members can only be used by methods of the class.
* Protected members can be used only by methods of the class, within the
	package, or methods of the subclass.

Is-a Relationship: Inheritance should imply an is-a relationship between the
superclass and the subclass. A ball "is a" sphere. Object type compatibility. An
instance of a subclass can be used instead of an instance of the superclass, but
not the other way around.

Has-a Relationship: Also called containment. Cannot be implemented using
inheritance. A pen "has a" ball.

##Dynamic Binding and Abstract Classes

Polymorphic methods have multiple meanings. Created when a subclass overrides a
method of the superclass. Late binding or dynamic binding: the appropriate
version of a polymorphic method is decided at execution time. _pg. 466_
Controlling whether a subclass can override a superclass method. Field modifier
`final` prevents a method from being overridden by a subclass. Field modifier
`abstract` requires the subclass to override the method. Early binding or static
binding: the appropriate version of a method is decided at compilation time.
Used by methods that are final or static.

Study through end of chapter 9. (maybe just to pg. 469)

Self tests in book!

Identify if valid prefix.
Convert from infix to postfix.
write read grammar
know all operations of stacks, queues, etc.
traverse a list

