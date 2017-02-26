#include<stdio.h>

int main()
{
	/*
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
	printf("\nMelissa:\nI am %d years old.\n", Melissa);

	//Where do you live?
	printf("I live at %p\n", &Melissa);
	*/

	//What if Stan ages? We have to keep checking his age
	//and updating Melissa's age constantly.
	//We can make this easier by saying that her age is the
	//same as the age of the person in Stan's house
	
	int Stan = 21;

	int *Melissa;
	Melissa = &Stan;

	printf("I live at %p\n", &Stan);

	printf("I am the same age as the person at %p\n", Melissa);

	printf("I am %d years old.\n", *Melissa);

	Stan++;

	printf("I am %d years old.\n", *Melissa);

	return 0;
}
