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


int bubble_sort(int *a, int n)
{
	int i = 0;
	int j = 0;
	int tmp = 0;

	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - i - 1; j++) {
			if (a[j] >= a[j + 1]) {
				tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
			show(a, n);
		}
	}

	return 0;
}

int main()
{
	int a[] = {1, 3, 2, 5, 7, 1, 5, 8};
	int n = sizeof(a)/sizeof(a[0]);

	bubble_sort(a, n);

	show(a, n);

	return 0;
}
