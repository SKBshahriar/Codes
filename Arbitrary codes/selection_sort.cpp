#include<stdio.h>
int main()
{
    int i,j,k,temp,n,mini;
    int a[100];
    scanf("%d",&n);
    for(i=0;i<n;i++)
         scanf("%d",&a[i]);
    for(i=0;i<n;i++)
    {
        mini=a[i];
        for(j=i+1;j<n;j++)
        {
            if(mini>a[j])
            {
                mini=a[j];
                k=j;
            }
        }
    if(a[i]!=mini)
    {
        temp=a[k];
        a[k]=a[i];
        a[i]=temp;
    }
    }
     for(i=0;i<n;i++)
        printf("%d ",a[i]);
     return 0;
}
