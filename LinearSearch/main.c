#include <stdio.h>
#include <stdlib.h>

int linear_search(int *elements, int num_elements, int target)
{
	int i = 0;

	for (i = 0; i < num_elements; i++) {
		if (elements[i] == target)
			return i;
	}

	return -1;
}

int main()
{
	int elements[] = {3, 7, 14, 20, 23, 32, 41, 44, 56, 57, 73, 89, 93};
	int num_elements = 0;
	int index = 0;

	num_elements = sizeof(elements)/sizeof(elements[0]);
	index = linear_search(elements, num_elements, 44);

	printf("Index of 44 = %d\n", index);

	return 0;
}

