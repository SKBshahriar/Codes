#include<stdio.h>
#include<conio.h>
#include<string.h>
int main()
{
    char a[20],b[20];
    int i,j;
    gets(a);
    gets(b);
    j=strcmp(a,b);
    if(j>0){
        printf("1st string is bigger");}
    else if(j<0){
        printf("2nd string is bigger");
    }
    getch();
}
