#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	int arr[100000], n, i, j, temp;
	scanf("%d", &n);
	srand(time(NULL));
	for (i = 0; i < n; i++)
	{
		arr[i] = rand()%20000+1;
	}
	printf("\nBefore Sort\n");
	for (i = 0; i < n; i++)
	{
		printf("%8d", arr[i]);
	}
	for (i = 1; i < n; i++)
	{
		for (j = i - 1; j >= 0 && arr[j + 1] < arr[j];)
		{
			temp = arr[j];
			arr[j] = arr[j + 1];
			arr[j + 1] = temp;
			j--;
		}
	}
	printf("\nAfter Sort\n");
	for (i = 0; i < n; i++)
	{
		printf("%8d", arr[i]);
	}
	_getch();
}