#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin>>n;
    vector<int>solve(n);
    for(auto &x:solve){cin>>x;}
    int x;
    cin>>x;
    vector<int>dp(n);
    for(int x=0; x<n; x++)
    {
        dp[x]=min(dp[x-1]+1,min(dp[x-3]+1,dp[x-4]+1));
    }
    cout<<dp[n]<<endl;
}
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        solve();

    }
}
