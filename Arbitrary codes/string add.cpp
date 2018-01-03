#include<stdio.h>
#include<conio.h>
int main()
{
	char a[20],b[20],c[20];
	int i,j;
	gets(a);
	gets(b);
	for(i=0,j=0;a[i]!='\0';i++,j++){
		c[j]=a[i];}
	for(i=0;b[i]!='\0';j++,i++){
		c[j]=b[i];}
	c[j]='\0';
	printf("%s",c);
	getch();
}

