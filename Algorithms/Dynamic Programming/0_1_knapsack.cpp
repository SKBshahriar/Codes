#include <bits/stdc++.h>

using namespace std;

int weight[1010];
int price[1010];
int dp[1010][1010];
int choice[1010][1010];

int knapsack(int n, int limit)
{
    if(n < 0 || limit == 0) return 0;
    if(dp[n][limit] != -1) return dp[n][limit];
    dp[n][limit] = knapsack(n - 1, limit);
    choice[n][limit] = 0;
    if(weight[n] <= limit){
        int temp = price[n] + knapsack(n - 1, limit - weight[n]);
        if(temp > dp[n][limit]){
            dp[n][limit] = temp;
            choice[n][limit] = 1;
        }
    }
    return dp[n][limit];
}

void print_knapsack(int n, int limit)
{
    if(n < 0 || limit == 0) return;
    if(choice[n][limit] == 1){
        print_knapsack(n - 1, limit - weight[n]);
        printf("%d ", n);
    }
    else{
        print_knapsack(n - 1, limit);
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    memset(dp, -1, sizeof(dp));
    int n, limit;
    cin >> n >> limit;
    for(int i = 0; i < n; i++){
        cin >> weight[i] >> price[i];
    }
    int ans = knapsack(n - 1, limit);
    cout << ans << "\n";
    print_knapsack(n - 1, limit);
}
