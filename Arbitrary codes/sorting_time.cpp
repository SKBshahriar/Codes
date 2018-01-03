#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<time.h>
#include<algorithm>
#define SIZE 2000000
using namespace std;
long a[SIZE];
void insertion_sort()
{
    int  i, j, temp;
	srand(time(NULL));
	for (i = 0; i < SIZE; i++)
	{
		a[i] = rand()%SIZE+1;
	}
	for (i = 1; i < SIZE; i++)
	{
		for (j = i - 1; j >= 0 && a[j + 1] < a[j];)
		{
			temp = a[j];
			a[j] = a[j + 1];
			a[j + 1] = temp;
			j--;
		}
	}
}
void bubble_sort()
{
    int i,j,temp;
    srand(time(NULL));
	for (i = 0; i < SIZE; i++)
	{
		a[i] = rand()%SIZE+1;
	}
	for (i = 1; i < SIZE; i++)
	{
		for (j = 0; j<SIZE - i; j++)
		{
			if (a[j]>a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}
int pratition(long a[],int i,int j)
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
void quicksort(long a[],int start,int end)
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
    long i=0,j=0,temp;
    clock_t begin, end;
    double time_spent;
    begin = clock();
//insertion_sort();
    srand(time(NULL));
    for (i = 0; i < SIZE; i++)
    {
        a[i] = rand()%SIZE+1;
    }
    //quicksort(a,0,SIZE-1);
    sort(a,a+SIZE);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("\nTime Elapsed:%f\n",time_spent);
    cout<<"\nClock Per Second : "<<CLOCKS_PER_SEC;
    return 0;
}

