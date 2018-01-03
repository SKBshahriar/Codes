#include<iostream>
using namespace std;
int A[1000];
int S[1000];
int V[1000];
int x;
int long_sub_sequence(int n)
{
	int temp;
	if (V[n]!=-1)
		return V[n];
	int max = 1;
	if (A[n] >= A[n - 1]) {
		x = n-1;
		temp = 1 + long_sub_sequence(n - 1);
		S[n] = A[n];
	}
	else {
		temp = long_sub_sequence(n - 1);
	}
	if (max < temp)
		max = temp;
	return max;
}
int main()
{
	int i, temp, flag = 0;
	A[0] = 10; A[1] = 22; A[2] = 9; A[3] = 33; A[4] = 21; A[5] = 50; A[6] = 60; A[7] = 60; A[8] = 80;
	for (i = 0; i < 9; i++)
		S[i] = -1;
	for (i = 0; i < 1000; i++)
		V[i]=-1;
	V[0] = 1;
	cout << long_sub_sequence(8) << endl;
	S[0] = A[x];
	for (i = 0; i < 9; i++) {
		if(S[i]!=-1)
			cout << S[i] << " ";
	}
	return 0;
}