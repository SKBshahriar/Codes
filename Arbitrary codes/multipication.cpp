#include<stdio.h>
#include<string.h>
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
int main()
{
    int i,ans,count=0,n=0,arr[9999],t,j,k,l,x,y,z,p,q,ii,jj;
    char digit[9999],digit2[9999],digit3[1000][1000];
    gets(digit);
    gets(digit2);
    for(jj=0;digit[jj]!='\0';jj++)
        digit[jj]=digit[jj]-48;
    for(ii=0;digit2[ii]!='\0';ii++)
        digit2[ii]=digit2[ii]-48;
    n=ii;
    count=jj;
    l=count;
    for(i=0; i<999; i++)
    {
        for(j=0; j<999; j++)
        {
            digit3[i][j]=0;
        }
    }
    for(i=n-1,x=0; i>=0; i--,x++)
    {
        t=0;
        q=0;
        z=((n-1)-i);
        y=200;
        p=y-z;
        for(j=count-1,y=p; j>=0; j--,y--)
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
    for(i=200; i>y; i--)
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
    for(i=0; i<z; i++)
        printf("%d",digit[i]);
}
