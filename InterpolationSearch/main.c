#include <stdio.h>
#include <stdlib.h>

/*
 * e[high] - e[low]      target - e[low]
 * ----------------  =  ------------------
 *    high - low          index - low

                       target - e[low]
	index = low + ------------------ x (high - low)
                       e[high] - e[low]
 */
int interpolation_search(int *elements, int num_elements, int target)
{
	int low = 0;
	int high = num_elements - 1;
	int index = 0;

	while (low <= high) {
		index = low + \
			(target - elements[low]) * (high - low) / \
			(elements[high] - elements[low]);
		if (target < elements[index])
			high = index -1;
		else if (target > elements[index])
			low = index + 1;
		else
			return index;
	}

	return -1;
}

int main()
{
	int elements[] = {3, 7, 14, 20, 23, 32, 41, 44, 56, 57, 73, 89, 93};
	int num_elements = 0;
	int index = 0;

	num_elements = sizeof(elements)/sizeof(elements[0]);
	index = interpolation_search(elements, num_elements, 44);

	printf("Index of 44 = %d\n", index);

	return 0;
}

