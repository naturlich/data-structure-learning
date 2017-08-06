#include <stdio.h>

void show(int *a, int n)
{
	int i = 0;

	if (!a)
		return;

	for (i = 0; i < n; i++)
		printf("%d ", a[i]);

	printf("\n");
}

void swap(int *a, int index1, int index2)
{
	int tmp = 0;

	tmp = a[index1];
	a[index1] = a[index2];
	a[index2] = tmp;
}

int selection_sort(int *a, int n)
{
	int imax = 0;
	int i = 0;
	int j = 0;

	for (i = 0; i < n; i++) {
		imax = i;
		for (j = i; j < n; j++) {
			if (a[j] < a[imax])
				swap(a, j, imax);
		}
	}

	return 0;
}

int main()
{
	int a[] = {1, 3, 2, 5, 7, 1, 5, 8};
	int n = sizeof(a)/sizeof(a[0]);

	selection_sort(a, n);

	show(a, n);

	return 0;
}
