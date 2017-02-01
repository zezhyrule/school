NOTES - 2017/01/25

##References to Memory

In java, when we invoke the new operator we create an instance of a class:

`Circle c = new Circle()`

The variable "created" is called a reference. The data for the object is
stored in other memory location(s). The reference stores the memory
location of the object.

##Pointers

Data structure designed to store memory address and not values. Primitives
are simple integers translated by the compiler. The name of the variable
is enough to locate the data.

Arrays are contiguous. We keep track of the first element of the array and
each element is the next memory location. 

##Memory Operators

A pointer can point to the location of any type of variable. By default
pointers have no type. Declared by type and *: `int *ptr;`

Pointer holds memory address. We pass an address rather than value with &
like when you pass to a function by reference.

`int num = 5;
*ptr = &num;`

##Stan's Story

`
int main()
{
	//This is Stan
	int Stan;

	//Stan is currently 21 years old and
	//lives in a house, in this case his house
	//is a location in memory.
	Stan = 21;

	//Tell us how old you are
	printf("I am %d years old.\n", Stan);

	//Where do you live?
	printf("I live at %p\n", &Stan);

	//Melissa is the same age as Stan.
	//She too lives in a house
	int Melissa = Stan;

	//Tell us how old you are
	printf("I am %d years old.\n", Melissa);

	//Where do you live?
	printf("I live at %p\n", &Melissa);

	return 0;
}
`
##Dereferencing a Pointer

A pointer only stores a memory location. We can retrieve the value stored
in the location the pointer points to. Using the * operator on a pointer
will retrieve the value pointed to.

When assigning values, we copy what is stored by the value into another. 

A pointer exists in memory as well as stores memory location. We can
create another pointer to store a pointer's location as well. We make a
pointer to pointer by having ** before the name.

`
int main()
{
	int Stan = 22;
	int *Melissa = &Stan;

	//Dave knows the address where Melissa lives
	int **Dave = &Melissa;

	//Dave is as old as the person in Melissa's house
	printf("%p\n", &Stan);
	printf("%p\n", &Melissa);
	printf("%p\n", Dave);

	//How old is that? Double dereference
	printf("%d\n", **Dave);

	return 0;
}
`

##Dynamic Memory

We can dynamically create an array of unknown size. Use of 
`malloc(int <num of bytes>)` function under stdlib.h library takes a 
number of bytes representing the array and returns a pointer to the first
element. Returns a void* so must be cast to write pointer type. Use
`free(<dynamic pointer>)` to deallocate the memory. This will release the
memory back to the system. If not done can cause problems.
