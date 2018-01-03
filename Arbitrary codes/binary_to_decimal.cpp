#include<stdio.h>
int main(){

    long int binary,decimal=0,j=1,temp;
    printf("Enter any number any binary number: ");
    scanf("%ld",&binary);
    while(binary!=0){
         temp=binary%10;
        decimal=decimal+temp*j;
        j=j*2;
        binary=binary/10;
    }
    printf("%ld",decimal);
    return 0;
}
