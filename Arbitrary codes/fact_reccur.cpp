#include<stdio.h>
int i=1;
void rev(char a[],int n)
{
    int i,j,temp;
    i=0;
    j=n-1;
    while(i<=j)
    {
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
        i++;
        j--;
    }
}
int multipication(long long int a,char digit[],int count)
{
    int i,ans,n=0,t,j,k,x,y,z,p,q;
    long long int out;
    char digit2[9999],digit3[1000][1000];
    out=a;
    i=0;
    while(out!=0)
    {
        digit2[i]=out%10;
        out=out/10;
        i++;
    }
    n=i;
    rev(digit2,n);
    for(i=0;i<999;i++)
    {
        for(j=0;j<999;j++)
        {
            digit3[i][j]=0;
        }
    }
    for(i=n-1,x=0;i>=0;i--,x++)
    {
        t=0;
        q=0;
        z=((n-1)-i);
        y=999;
        p=y-z;
        for(j=count-1,y=p;j>=0;j--,y--)
        {
            ans=digit[j]*digit2[i];
            if(t==1)
                ans=ans+k;
            if(ans>9)
            {
                k=ans/10;
                ans=ans-(10*k);
                digit3[x][y]=ans;
                t=1;
            }
            else
            {
                digit3[x][y]=ans;
                t=0;
            }
            if(j==0 && t!=0)
            {
                digit3[x][y-1]=k;
                q=1;
            }
        }
    }
    if(q==1)
        y--;
    t=0;
    z=0;
    for(i=999; i>y; i--)
    {
        ans=0;
        for(j=0; j<x; j++)
        {
            ans=ans+digit3[j][i];
        }
        if(t==1)
            ans=ans+k;
        if(ans>9)
        {
            k=ans/10;
            ans=ans-(10*k);
            digit[z]=ans;
            t=1;
        }
        else
        {
            digit[z]=ans;
            t=0;
        }
        if(i==(y+1) && t!=0)
        {
            digit[z+1]=k;
            z++;
        }
        z++;
    }
    rev(digit,z);
    return z;
}
void fact(long long int n,char digit[])
{
    if(n==0)
    {
        digit[0]=0;
        return;
    }
    if(n==1)
        return;
    fact(n-1,digit);
    i=multipication(n,digit,i);
}
int main()
{
    long long int n;
    int j;
    char digit[9999];
    digit[0]=1;
    scanf("%lld",&n);
    fact(n,digit);
    for(j=0;j<i;j++)
        printf("%d",digit[j]);
    return 0;
}
