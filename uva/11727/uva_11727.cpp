#include<stdio.h>
int main()
{
    int a,b,c,n,i,h,l;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        if(a>b && a>c)
            h=a;
        else if(b>c && b>a)
            h=b;
        else if(c>a && c>b)
            h=c;
        if(a<b && a<c)
            l=a;
        else if(b<c && b<a)
            l=b;
        else if(c<a && c<b)
            l=c;
        if(a!=h && a!=l)
            printf("Case %d: %d\n",i+1,a);
        if(b!=h & b!=l)
            printf("Case %d: %d\n",i+1,b);
        if(c!=h && c!=l)
            printf("Case %d: %d\n",i+1,c);

    }
    return 0;
}
