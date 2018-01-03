#include<stdio.h>
#include<conio.h>
int main()
{
	FILE *p1;
	p1=fopen("first.txt","r");
	int x[10],i;
	for(i=0;i<10;i++)
	{
		fscanf(p1,"%d",&x[i]);
		printf("%d ",x[i]);
	}
	getch();
}
