#include<stdio.h>
int pratition(int a[],int i,int j)
{
	int pivot, temp, k;
	k = i + 1;
	int pivot1 = a[i];
	while (k <= j)
	{
		while (a[k] <= pivot1)
			k++;
		while (a[j] > pivot1)
			j--;
		if (k < j)
		{
			temp = a[k];
			a[k] = a[j];
			a[j] = temp;
		}
	}
	temp = a[j];
	a[j] =a[i] ;
	a[i] = temp;
	return j;

}
void quicksort(int a[],int start,int end)
{
	if (end > start)
	{
		int index = pratition(a, start, end);
		quicksort(a, start, index - 1);
		quicksort(a, index + 1, end);
	}
}
int main()
{
	int i, j, n;
	int a[10000];
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	quicksort(a, 0, n - 1);
	for (i = 0; i < n; i++)
		printf("%d ",a[i]);
	return 0;
}
