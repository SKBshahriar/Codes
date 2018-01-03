#include<stdio.h>
int max(int a[],int n)
{
    int i,m,ind;
    m=a[0];
    ind=0;
    for(i=0; i<n; i++)
    {
        if(a[i]>m)
        {
            m=a[i];
            ind=i;
        }
    }
    return ind;
}
int min(int a[],int n)
{
    int i,m,ind;
    m=a[0];
    ind=0;
    for(i=0; i<n; i++)
    {
        if(a[i]<m)
        {
            m=a[i];
            ind=i;
        }
    }
    return ind;
}
int check(int a[],int n,int height)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        if(a[i]!=height)
            return 0;
    }
    return 1;
}
int main()
{
    int i,j,k,n,a[100],b[100],ind=0,count,sum=0,height,high,low;
    while(1)
    {
        sum=0;
        scanf("%d",&n);
        if(n==0)
            break;
        for(i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
            sum=sum+a[i];
        }
        height=sum/n;
        count =0;
        while(check(a,n,height)!=1)
        {
            high = max(a, n);
			low = min(a, n);
			k = a[high]-height;
			a[high]=a[high] - k;
			if((a[low] + k)<=height)
            {
                a[low]=a[low] + k;
            }
            else
            {
                j=(a[low]+k)-height;
                a[high]=a[high]+j;
                k=k-j;
                a[low]=a[low]+k;
            }
			count = count + k;
        }
        printf("Set #%d\nThe minimum number of moves is %d.\n\n",ind+1,count);
        ind++;
    }
   return 0;
}

