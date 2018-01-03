#include<stdio.h>
void binary_search(int a[],int low,int high,int key)
{
    int mid;
    mid=(low+high)/2;
    if(low>high)
    {
        printf("Not Found");
        return;
    }
    if(a[mid]==key)
    {
        printf("Found");
        return;
    }
    else if(a[mid]>key)
       binary_search(a,low,mid-1,key);
    else
        binary_search(a,mid+1,high,key);
}
int main()
{
    int a[100],key,n,i;
    printf("Enter Size Of The Array : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Enter The Key : ");
    scanf("%d",&key);
    binary_search(a,0,n-1,key);
    return 0;
}
