#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
void MaxHeap(long a[], int index, int n)
{
	int left, right, large;
	left = index * 2;
	right = (index * 2) + 1;
	large = index;
	if (left <= n && a[left] > a[large])
		large = left;
	if (right <= n && a[right] > a[large])
		large = right;
	if (large == index)
		return;
	else
	{
		swap(a[large], a[index]);
		MaxHeap(a, large, n);
	}
}
void BuildHeap(long a[], int n)
{
	int i;
	for (i = n; i>= 1; i--)
		MaxHeap(a, i, n);
}
void HeapSort(long a[], int n)
{
	BuildHeap(a, n);
	while (n > 1)
	{
		swap(a[n],a[1]);
		n--;
		MaxHeap(a, 1, n);
	}
}
int main()
{
	long a[10000];
	int i, n;
	cin >> n;
	srand(time(NULL));
	for (i = 1; i <= n; i++)
		a[i] = rand() % n + 1;
	for (i = 1; i <= n; i++)
		cout <<a[i] << " ";
	cout << endl;
	HeapSort(a, n);
	for (i = 1; i <= n; i++)
		cout << a[i] << " ";
	return 0; 
}