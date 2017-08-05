#include <stdlib.h>
#include <stdio.h>

int bucket_sort(int *a, int n)
{
	int i = 0;
	int j = 0;
	int buckets[n];

	for (i = 0; i < n; i ++)
		buckets[i] = 0;

	for (i = 0; i < n; i++)
		buckets[a[i]]++;

	for (i = 0, j = 0; i < n; i++) {
		for (; buckets[i]; buckets[i]--)
			a[j++] = i;
	}

	return 0;
}

void print_array(int *a, int n)
{
	int i = 0;

	for (i = 0; i < n; i++)
		printf("%d ", a[i]);

	printf("\n");
}

int main()
{
	int a[] = {5, 6, 9, 1, 10, 2, 4, 3, 3, 2, 4};
	int n = sizeof(a)/sizeof(a[0]);
	int i = 0;

	print_array(a, n);
	bucket_sort(a, n);
	print_array(a, n);

	return 0;
}
