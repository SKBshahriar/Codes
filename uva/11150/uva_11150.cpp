#include<stdio.h>
int main()
{
    int a,b,c,count;
    while(scanf("%d",&a)!=EOF)
    {
        count=a;
        while(a>1)
        {
            if(a==2)
                a++;
            b=a/3;
            c=a%3;
            a=b+c;
            count=count+b;
        }
        printf("%d\n",count);
    }
    return 0;
}
