#include<stdio.h>
#include<stdlib.h>

// updated comments will be online

int main(int argc, char **argv)
{
	int num, i, *ptr, sum = 0;

	printf("Enter number of elements: ");
	scanf("%d", &num);

	ptr = (int*) malloc(num * sizeof(int)); // memory allocated

	if (ptr == NULL)
	{
		printf("Error! Memory not allocated.");
		exit(0);
	}

	printf("Enter elements of array: ");

	for (i = 0; i < num; ++i)
	{
		scanf("%d", &ptr[i]);
	}

	printf("\n\n");

	for (i = 0; i < num; ++i)
	{
		printf("%d\n", *(ptr + i));
		sum += ptr[i];
	}

	printf("Sum = %d", sum);

	free(ptr); // memory deallocated

	return 0;
}
