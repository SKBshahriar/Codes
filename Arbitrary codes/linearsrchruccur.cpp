#include<stdio.h>
void lsearch(int a[],int i,int key)
{
    if(i<0)
    {
        printf("Not Found");
        return;
    }
    if(a[i]==key)
    {
        printf("Found!");
        return;
    }
    else
        lsearch(a,i-1,key);
}
int main()
{
    int a[50],i,j,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter The Key : ");
    scanf("%d",&j);
    lsearch(a,n-1,j);
    return 0;
}
