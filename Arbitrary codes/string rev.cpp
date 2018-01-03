#include<stdio.h>
#include<conio.h>
int main()
{
	char a[100],b[100];
	int i,j,n=0;
	printf("Enter The String To reverse\n");
	gets(a);
	for(i=0;a[i]!='\0';i++){
		n++;
	}
	for(i=0,j=n-1;j>=0;j--,i++){
		b[i]=a[j];
	}
	b[i]='\0';
	printf("%s",b);
	getch();
}

