#include<stdio.h>
int main()
{
    long int decimal,temp;
    int binary[100],i=1,j;
    printf("Enter any decimal number: ");
    scanf("%ld",&decimal);
    temp = decimal;
    while(temp!=0)
    {
        binary[i]= temp % 2;
        temp = temp / 2;
        i++;
    }
    for(j = i -1 ; j> 0; j--)
        printf("%d",binary[j]);
    return 0;
}
