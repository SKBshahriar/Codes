#include<stdio.h>
int main()
{
    long long int land,animal,degree,ans,ans2,a[100],f=0;
    int i,j,k,n;
    while(1)
    {
        f=0;
        if(scanf("%d",&n)==EOF)
            return 0;
        for(i=0; i<n; i++)
        {
            scanf("%d",&k);
            ans=0;
            ans2=0;
            for(j=0; j<k; j++)
            {
                scanf("%lld%lld%lld",&land,&animal,&degree);
                ans=land*degree;
                ans2=ans2+ans;
            }
            a[f]=ans2;
            f++;
        }
        for(i=0;i<f;i++)
            printf("%lld\n",a[i]);
    }
    return 0;
}
