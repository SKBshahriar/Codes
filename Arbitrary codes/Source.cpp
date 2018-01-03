#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
int main()
{
	int i , j, k, l, m, n, o, t, a, b, x[100], y[100], inp, out;
	scanf("%d", &t);
	for (o = 0; o < t; o++)
	{
		i = 0;
		scanf("%d%d", &a, &b);
		while (a > 0)
		{
			out = a % 10;
			a = a / 10;
			x[i] = out;
			i++;
		}
		while (b > 0)
		{
			out = b % 10;
			b = b / 10;
			x[i] = out;
			i++;
		}
		i--;
		for (j = 1; j <=i-1; j++)
		{
			for (k = 0; k < i; k++)
			{
				if (x[k]>x[k + 1])
				{
					m = x[k];
					x[k] = x[k + 1];
					x[k + 1] = m;
				}
			}
		}
		for (n = 0; n <= i; n++)
		{
			printf("%d",x[n]);
		}
		printf("\n");
	}
	_getch();
}