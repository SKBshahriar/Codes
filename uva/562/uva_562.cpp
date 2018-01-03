#include<bits/stdc++.h>
using namespace std;
int coin[110];
int dp[110][130000];
int call(int sum, int i, int n)
{
	if (dp[i][sum] != -1) return dp[i][sum];
	if (sum == 0) return 0;
	if (i >= n) return INT_MAX;
	int dif;
	if (i > 0)  dif = sum - coin[i]*2;
	else  dif = coin[i] - (sum - coin[i]);
	int temp = min(abs(dif), call(dif, i + 1, n));
	int temp2 = call(sum, i + 1, n);
	return dp[i][sum]=min(temp, temp2);

}
int main()
{
	int n;
	cin >> n;
	for (int i = 0;i<n;i++) {
		int m, sum = 0;
		memset(dp, -1, sizeof(dp));
		cin >> m;
		for (int j = 0;j<m;j++) {
			cin >> coin[j];
			sum += coin[j];
		}
		sort(coin, coin + m, greater<int>());
		cout << call(sum, 0, m)<<endl;
	}
	return 0;
}
