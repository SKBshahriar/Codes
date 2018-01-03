#include<stdio.h>
#include<conio.h>
struct ff{
	int f;
	int g;
};
int main()
{
	struct ff x[4];
	FILE *p1,*p2,*p3;
	p1=fopen("first.txt","r");
	p2=fopen("2nd.txt","w");
	p3=fopen("3rd.txt","w");
	int i;
	for(i=0;i<4;i++)
	{
		fscanf(p1,"%d%d",&x[i].f,&x[i].g);
	}
	for(i=0;i<4;i++)
	{
		fprintf(p2,"%d\n",x[i].f);
	}
	for(i=0;i<4;i++)
	{
		fprintf(p3,"%d\n",x[i].g);
	}
	fclose(p1);
	fclose(p2);
	fclose(p3);
	getch();
}
