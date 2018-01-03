
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<limits.h>
int l[1000],r[1000];
void merge(int a[],int front,int mid,int rear)
{
    int n1,n2,i,j,k;
    n1=mid-front+1;
    n2=rear-mid;
    for(i=0;i<n1;i++)
        l[i]=a[front+i];
    for(i=0;i<n2;i++)
        r[i]=a[mid+1+i];
    l[n1]=INT_MAX;
    r[n2]=INT_MAX;
    i=0;j=0;
    for(k=front;k<=rear;k++)
    {
        if(l[i]<=r[j])
        {
            a[k]=l[i];
            i++;
        }
        else
        {
            a[k]=r[j];
            j++;
        }
    }
}
void merge_sort(int a[],int front,int rear)
{
    int mid;
    if(front<rear)
    {
        mid=(rear+front)/2;
        merge_sort(a,front,mid);
        merge_sort(a,mid+1,rear);
        merge(a,front,mid,rear);
    }
}
int main()
{
    int a[1000],n,i;
    scanf("%d",&n);
    srand(time(NULL));
    for(i=0;i<n;i++)
        a[i]=rand()%n+1;
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
    merge_sort(a,0,n);
     for(i=0;i<n;i++)
        printf("%d ",a[i]);
}
