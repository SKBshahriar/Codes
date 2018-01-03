#include <bits/stdc++.h>

using namespace std;

string A, B;

int dp[1010][1010];
int lcs(int i, int j)
{
    if(i >= A.length() || j >= B.length()) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int ret = 0;
    if(A[i] == B[j])
        ret = 1 + lcs(i + 1, j + 1);
    else
        ret = max(lcs(i + 1, j), lcs(i, j + 1));
    return dp[i][j] = ret;
}

void print(int i, int j)
{
    if(i >= A.length() || j >= B.length()) return;
    if(A[i] == B[j]){
        printf("%c", A[i]);
        print(i + 1, j + 1);
    }
    else if(dp[i + 1][j] >= dp[i][j + 1]){
        print(i + 1, j);
    }
    else{
        print(i, j + 1);
    }
}

int main()
{
    memset(dp, -1, sizeof(dp));
    cin >> A >> B;
    int ans = lcs(0, 0);
    cout << ans << "\n";
    print(0, 0);
}
