#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<string.h>
int main()
{
	char a[50], b[50];
	int i = 0, j = 0, k;
	gets(a);
	while (a[i] != '\0')
	{
		while (a[j] != '\0' && a[j] != ' ')
			j++;
		for (k = 0; k<(j - i); k++)
		{
			b[k] = a[i + k];
		}
		b[k] = '\0';
		puts(b);
		i = j;
		while (a[i] == ' ')
			i++;
		j = i;
	}
	_getch();
}