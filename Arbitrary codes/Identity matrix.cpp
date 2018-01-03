#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<string.h>
int main()
{
	int a[10][10], i, j, k=1, rc;
	printf("Enter the no of row and column: ");
	scanf("%d", &rc);
	printf("Enter the Matrix\n");
	for (i = 0; i < rc; i++)
	{
		for (j = 0; j < rc; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	for (i = 0; i < rc; i++)
	{
		for (j = 0; j <= rc; j++)
		{
			if (a[i][j] == 0 && a[i][i] == 1)
				k = 0;
			else
				break;
		}
	}
	printf("\n\n");
	for (i = 0; i < rc; i++)
	{
		for (j = 0; j < rc; j++)
		{
			printf("\t%d", a[i][j]);
		} 
		printf("\n");
	}
	if (k == 0)
		printf("\n\tThis is a idintety matrix");
	else
		printf("\n\tThis is not a idintety matrix");
	_getch();
}