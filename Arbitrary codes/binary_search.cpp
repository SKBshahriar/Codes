#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
int bsearch(int a[], int item, int n)
{
	int i, j, k, low = 0, high = (n - 1), mid;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (a[mid] == item)
		{
			return 1;
		}
		else if (a[mid]>item)
			high = mid - 1;
		else
			low = mid + 1;
	}
	if (low>high)
		return 0;
}
int main()
{
	int arr[100000], n, j, inp, i, k, low = 0, high, temp;
	scanf("%d", &n);
	srand(time(NULL));
	for (i = 0; i<n; i++)
	{
		arr[i] = rand() % 30000 + 1;
	}
	for (i = 1; i<n; i++)
	{
		for (j = 0; j<n - i; j++)
		{
			if (arr[j]>arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	printf("\n");
	for (i = 0; i<n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	scanf("%d", &inp);
	k = bsearch(arr, inp, n);
	if (k == 1)
		printf("\nFound");
	else
		printf("\nNot Found");
	_getch();
}