#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	int i, j, n, k, temp;
	int arr[100];
	scanf("%d", &n);
	srand(time(NULL));
	for (i = 0; i < n; i++)
	{
		arr[i] = rand() % 100 + 1;
	}
	printf("\nBrfore Sort\n");
	for (i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	for (i = 1; i < n; i++)
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
	printf("\nAfter Sort\n");
	for (i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	_getch();
}