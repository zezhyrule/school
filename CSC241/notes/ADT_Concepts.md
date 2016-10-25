NOTES - 09/13/16

pg59    has an example of reading an unknown number of values

Ch. 4 of Data Abstraction & Problem Solving: Walls and Mirrors

##Implementing ADTs

##Java Classes Revisited

OOP views a program as a collection of objects. Encapsulation
is a principle of OOP. It can be used to enforce the walls of
an ADT. It Combines an ADT's data with its method to form an abject.
Hides the implementation details of the ADT from the programmer who uses it.

When we use a standard class method, we only need to know the method name, the
parameter information, the return value, and what the method does. The user
doesn't need to know anything about the implementation details.

A java class is a new data type whose instances are objects. It has class
members such as data fields (almost always private) and methods. All members
are private unless the programmer designates them as public. Classes also
contain a Constructor, which is a method that creates and initializes new
instances of a class. It has the same name as the class and no return type.

Java's garbage collection mechanism automatically destroys objects that a
program no longer references.

Constructors allocate memory for an abject and can initialize the object's
data. A class can have more than one constructor. The default constructor has
no parameters and typically initializes data fields to values the class
implementation chooses.

If you don't include a constructor, the compiler will automatically generate
one (compiler-generated constructor). 

A function called a constructor is automatically invoked when a variable

A constructor allocates memory for an object and initializes the object to a
value. A class can have more than one constructor. The defaulst constructor
has no arguments.

So, the statement
	Sphere unitSphere = new Sphere();
invokes the default constructor. 

_Exapmle amount of documentation for methods can be found on the
Sphere.java file._

##Using a Class

Clients are user programs with access to a particular class. Clients can declare and manipulate objects of that class.

##Information Hiding

When implementing a class, we need:
* How to store the data
* Variables
* Functions to manipulate the data

The above are *private* to the class. The client needs only the *public* methods that are specified and declared for the class.


##Objects

Once we have the data structure (class) defined, we can declare variables to be of that type. We call variables *objects* of the class, or *instances* of the data structure. We use methods to access the object.

##ADT List Operations (pg. 204)
1. Create an empty list
2. Determine whether a list is empty
3. Determine the number of items on a list
4. Insert an item at a given position in the list
5. Delete th item at a given position in the list
6. Remove all items from the list
7. Look at (retrieve) the item at a given position in the list

Specifications of the ADT operations
* Define the contract for the ADT list
* Do not specify how to store the list or how to perform the operations.

ADT operations can be used in an application without the knowledge of how the operations will be implemented.

To implement the ADT list, we will begin with an array-based implementation of the ADT list. Note that the list is not an array - the ADT list has some operations that an array does not. _See pages 226-232_

On _pg 231_ look at ListArrayBased.java. 

####ADT

instr/Sphere.java is an ADT. 

##Lab 2

ADT Implementation and Use
Due: Tuesday, 9/27/16

Based on problem 3 in the textbook. 
