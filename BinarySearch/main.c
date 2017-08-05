#include <stdlib.h>
#include <stdio.h>

int binary_search(int *elements, int num_elements, int target)
{
	int low = 0;
	int high = num_elements - 1;
	int middle = 0;

	while (low <= high) {
		middle = (low + high) / 2;

		if (target < elements[middle])
			high = middle - 1;
		else if (target > elements[middle])
			low = middle + 1;
		else
			return middle;
	}

	return -1;
}

int main()
{
	int elements[] = {3, 7, 14, 20, 23, 32, 41, 44, 56, 57, 73, 89, 93};
	int num_elements = 0;
	int index = 0;

	num_elements = sizeof(elements)/sizeof(elements[0]);
	index = binary_search(elements, num_elements, 44);

	printf("Index of 44 = %d\n", index);

	return 0;
}
