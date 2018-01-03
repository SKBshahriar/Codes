#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
int main()
{
	float high, mid, low = 0, inp, num;
	scanf("%f", &inp);
	high = inp;
	while (high >= low)
	{
		mid = (low + high) / 2.0;
		num =mid*mid;
		if ((num + 0.0005) >= inp && num <= inp)
		{
			printf("\n%.3f", mid);
			break;
		}
		else if (num < inp)
			low = mid;
		else if (num > inp)
			high = mid;
	}
	_getch();
}