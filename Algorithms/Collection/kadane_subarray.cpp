#include<bits\stdc++.h>
using namespace std;
int kadane(int A[],int n,int *f,int *l)
{
	int sum=0;
	int max_sum=INT_MIN;
	*l=-1;
	int temp=0;

	for(int i=0;i<n;i++)
	{
		sum+=A[i];
		if(sum<0)
		{
			sum=0;
			temp=i+1;
		}
		else if(sum>max_sum)
		{
			max_sum=sum;
			*f=temp;
			*l=i;
		}
	}

	if(*l!=-1)
		return max_sum;

	max_sum=A[0];

	for(int i=1;i<n;i++)
	{
		 if(A[i]>max_sum)
		 {
		 	max_sum=A[i];
		 	*f=i+1;
		 	*l=*f;
		 }
	}

	return max_sum;
}
int main()
{
	int arr[]={-11,-23,-5,-4,-6,-4,-8,-9,-8};
	int start,last;
	int s=kadane(arr,9,&start,&last);
	cout<<start<<" to "<<last<<" sum is "<<s;
	return 0;
}
