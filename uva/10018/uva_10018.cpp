#include<stdio.h>
unsigned long long int rev(long long int x){
	unsigned long long int outpt = 0,lastdig;
	while (x != 0)
	{
		outpt = outpt * 10;
		lastdig = (x % 10);
		outpt += lastdig;
		x = x / 10;
	}
	return outpt;
}
int main()
{
    unsigned long long int num,a,b,i,j;
    int count,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%llu",&a);
        count =0;
        while(1)
        {
            b=rev(a);
            if(a==b)
            {
                printf("%d %llu\n",count,a);
                break;
            }
            else
            {
                a=a+b;
                count++;
            }
        }
    }
    return 0;
}
