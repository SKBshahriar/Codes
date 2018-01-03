#include<iostream>
using namespace std;
int weight[1000];
int price[1000];
int s[1000];
int maximum(int x, int y)
{
	if (x >= y)
		return x;
	else
		return y;
}
int knapsack(int n,int W)
{
	if (W < 0)
		return 0;
	if (n < 0)
		return 0;
	int max = knapsack(n-1,W);
	if (weight[n] <= W)
	{
		int temp = knapsack(n - 1, W - weight[n]) + price[n];
		if (max < temp) {
			max = temp;
			int ind = W - weight[n];
			s[n] = W - weight[n];
		}
		int temp1 = knapsack(n - 1, W);
		if (max < temp1) {
			max = temp1;
			int ind = W - weight[n];
			s[n] = W - weight[n];
		}
		//max = maximum(knapsack(n - 1, W - weight[n]) + price[n], knapsack(n - 1, W));
		//s[W] = weight[n];
	}
	return max;
}
int main()
{
	int i, j;
	weight[0] = 5; weight[1] = 8; weight[2] = 1; weight[3] = 7; weight[4] = 12; weight[5] = 10;
	price[0] = 100; price[1] = 150; price[2] = 10; price[3] = 190; price[4] = 220; price[5] = 160;
	int W = 20;
	i = knapsack(5, W);
	cout << i<<endl;
	for (i = 0; i <=W; i++)
		cout << s[i]<<" ";
	cin >> i;
	return 0;
}