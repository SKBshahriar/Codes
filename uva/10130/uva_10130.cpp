#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int weight[1010];
int price[1010];
int dp[1010][1010];
int person[110];

int shopping(int n,int total)
{
	if(n<0 || total<1) return 0;
	if(dp[n][total]!=-1) return dp[n][total];

	dp[n][total] = shopping(n - 1, total);
	if (total >= weight[n])
	{
		int temp = price[n] + shopping(n - 1, total - weight[n]);
		if (temp > dp[n][total])
			dp[n][total] = temp;

	}
	return dp[n][total];
}

int main()
{
	int n,g,t;
	cin>>t;
	for(int test=0;test<t;test++){
		memset(dp,-1,sizeof(dp));
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>price[i]>>weight[i];
		cin>>g;
		for(int i=0;i<g;i++)
			cin>>person[i];
		int sum=0;
		for(int i=0;i<g;i++)
			sum+=shopping(n-1,person[i]);
		cout<<sum<<endl;
	}
}
