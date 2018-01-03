#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
int main()
{
	char a[50], b[50], c[50], d;
	int i, j, k, n;
	gets(a);
	scanf("%d", &n);
	fflush(stdin);
	scanf("%c", &d);
	for (i = 0, j = 0; i < n; i++, j++)
	{
		c[j] = a[i];
	}
	c[j] = d;
	j++;
	for (k = j-1; a[k] != '\0'; k++, j++)
	{
		c[j] = a[k];
	}
	c[j] = '\0';
	puts(c);

	_getch();
}