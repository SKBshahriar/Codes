#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
int main()
{
	int a = 0, hst = 0;
	long long int i, j, n = 0, b, x=0;
	while (scanf("%lld %lld", &i, &j) == 2)
	{
		printf("%lld %lld ", i, j);
		if (i > j)
		{
			j = i + j;
			i = j - i;
			j = j - i;
		}
		x = 0;
		while (i <= j)
		{
			a = 0;
			for (b = i; b >= 1;)
			{
				if (b == 1)
				{
					a++;
					break;
				}
				else if (b % 2 != 0)
				{
					b = 3 * b + 1;
					a++;
				}
				else if (b % 2 == 0)
				{
					b = b / 2;
					a++;
				}
			}
			i++;
			if (a > x)
				x = a;
		}
		printf("%d\n", x);
	}
	_getch();
}