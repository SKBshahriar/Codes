#include<stdio.h>
int main()
{
    int i,j,k,a,b,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&j,&k);
        if(k>j)
            printf("impossible\n");
        else
        {
            a=(j+k)/2;
            b=j-a;
            if((a+b)==j && (a-b)==k)
                printf("%d %d\n",a,b);
            else
                printf("impossible\n");
        }
    }
    return 0;
}
