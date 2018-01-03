#include<stdio.h>
#include<stdlib.h>
void srt(int arr[],int n)
{
    int i,j,temp;
    for (i = 1; i < n; i++)
	{
		for (j = i - 1; j >= 0 && arr[j + 1] < arr[j];)
		{
			temp = arr[j];
			arr[j] = arr[j + 1];
			arr[j + 1] = temp;
			j--;
		}
	}
}
int main()
{
    int a[3000],i,j,k,n,b[3000],f,flag;
    while(1)
    {
        f=0;
        if(scanf("%d",&n)==EOF)
            return 0;
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(i=0;i<n-1;i++)
        {
            k=a[i]-a[i+1];
            k=abs(k);
            b[f]=k;
            f++;
        }
        srt(b,f);
        flag=1;
        if(f==1)
        {
            if(b[0]!=1)
                flag=0;
        }
        for(i=0;i<f-1;i++)
        {
            k=b[i]-b[i+1];
            k=abs(k);
            if(k!=1)
                flag=0;
        }
        if(flag==1)
            printf("Jolly");
        else
            printf("Not jolly");
        printf("\n");
    }
    return 0;
}
