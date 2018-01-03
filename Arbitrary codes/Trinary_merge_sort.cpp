#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<limits.h>
int l[1000],r[1000],m[1000];
void merge(int a[],int front,int mid1,int mid2,int rear)
{
    int n1,n2,n3,i,j,k,x;
    n1=mid1-front+1;
    n2=mid2-mid1;
    n3=rear-mid2;
    for(i=0;i<n1;i++)
        l[i]=a[front+i];
    for(i=0;i<n2;i++)
        m[i]=a[mid1+1+i];
    for(i=0;i<n3;i++)
        r[i]=a[mid2+1+i];
    l[n1]=INT_MAX;
    m[n2]=INT_MAX;
    r[n3]=INT_MAX;
    i=0;j=0,x=0;
    for(k=front;k<=rear;k++)
    {
        //printf("s ");
        if(l[i]<=r[j] && l[i]<=m[x] )
        {
            a[k]=l[i];
            i++;
        }
        else if(r[j]<=l[i] && r[j]<=m[x] )
        {
            a[k]=r[j];
            j++;
        }
        else if(m[x]<=l[i] && m[x]<=r[j])
        {
            a[k]=m[x];
            x++;
        }
    }
}
void merge_sort(int a[],int front,int rear)
{
    int mid1,mid2,temp;
    if(front<rear)
    {
        temp=(rear-front+1)/3;
        mid1=front+temp;
        mid2=mid1+temp;
        merge_sort(a,front,mid1);
        merge_sort(a,mid1+1,mid2);
        merge_sort(a,mid2+1,rear);
        merge(a,front,mid1,mid2,rear);
    }
}
int main()
{
    int a[1000],n,i;
    scanf("%d",&n);
    srand(time(NULL));
    for(i=0;i<n;i++)
        a[i]=rand()%1000+1;
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
        printf("\n");
     merge_sort(a,0,n-1);
     for(i=0;i<n;i++)
        printf("%d ",a[i]);
}
