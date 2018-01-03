#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<string.h>
int main()
{
	char a[50], b[50],c[50];
	int i = 0, j = 0, k, count = 0, n,l;
	gets(a);
	gets(c);
	scanf("%d", &n);
	while (a[i] != '\0')
	{
		while (a[j] != '\0' && a[j] != ' '){
			j++;
		}
		count++;
		for (k=0; k < (j - i); k++)
		{
			b[k] = a[i + k];
		}
		if (n == count)
		{
			b[k] = ' ';
			k++;
			for (l = 0; c[l] != '\0'; k++, l++)
			{
				b[k] = c[l];
			}
		}
		b[k] = '\0';
		printf("%s ", b);
		i = j;
		while (a[i] == ' ')
			i++;
		j = i;
	}
	_getch();
}