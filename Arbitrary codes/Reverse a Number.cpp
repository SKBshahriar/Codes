#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
int rev(int x){
	int outpt = 0;
	while (x != 0)
	{
		outpt = outpt * 10;
		int lastdig = (x % 10);
		outpt += lastdig;
		x = x / 10;
	}
	return outpt;
}
int main()
{
	int d, f;
	scanf("%d", &d);
	f = rev(d);
	printf("%d", f);
	_getch();
}