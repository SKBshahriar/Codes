#include<bits/stdc++.h>
using namespace std;
string s,t;
int dp[1010][1010][15];
int call(int i,int j,int sofar,int k)
{
    if(dp[i][j][sofar]!=-1) return dp[i][j][sofar];
    if(i>=s.length() || j>=t.length()) return 0;
    if(sofar>=k) return 0;
    if(s[i]==t[j]){
        int len=0;
        for(int x=i, y=j;x<s.length() && y<t.length();x++,y++){
            if(s[x]==t[y]) len++;
            else break;
        }
     return dp[i][j][sofar]=max(len+ call(i+len,j+len,sofar+1,k),max(call(i+1,j,sofar,k),call(i,j+1,sofar,k)));
    }
    else return dp[i][j][sofar]=max(call(i+1,j,sofar,k),call(i,j+1,sofar,k));
}
int main()
{
    memset(dp,-1,sizeof(dp));
    int n,m,k;
    cin>>n>>m>>k;
    cin>>s>>t;
    cout<<call(0,0,0,k);
    return 0;
}
