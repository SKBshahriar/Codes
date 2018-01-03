#include<stdio.h>
int main()
{
    int i,j,k,count=0,arr[100],temp,np,n;
    scanf("%d",&np);
    for(k=0; k<np; k++)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&arr[i]);
        count=0;
        for (i = 1; i < n; i++)
        {
            for (j = 0; j<n - i; j++)
            {
                if (arr[j]>arr[j + 1])
                {
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    count++;
                }
            }
        }
        printf("Optimal train swapping takes %d swaps.\n",count);
    }
    return 0;
}
