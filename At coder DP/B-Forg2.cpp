#include<bits/stdc++.h>
#define vi vector<int>
using namespace std;
const int INF=1e9+7;
const int MAXN=1e6;

void solve()
{
    int n,k;
    cin>>n>>k;
    vector<int>v(n);
    vector<int>dp(n,INF);

    for(int i=0; i<n; i++)
    {
        cin>>v[i];
    }
    dp[0]=0;

    for(int i=1; i<n; i++)
    {
      for(int j=1; j<=k; j++)
      {
          if(i-j>=0)dp[i]=min(dp[i],dp[i-j]+abs(v[i]-v[i-j]));
      }
    }
    cout<<dp[n-1]<<endl;



}
int main()
{
    int t=1;
    //cin>>t;
    while(t--)
    {
        solve();
    }
}
