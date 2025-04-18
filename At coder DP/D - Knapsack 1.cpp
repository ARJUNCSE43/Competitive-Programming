#include<bits/stdc++.h>
#define vi vector<int>
#define ll long long

using namespace std;
int wt[105],val[105];
ll dp[105][100005];
ll func(int idx,int wt_left)
{
    if(wt_left==0)return 0;
    if(idx<0)return 0;
    if(dp[idx][wt_left]!=-1)return dp[idx][wt_left];
    ll ans=func(idx-1,wt_left);
    if(wt_left-wt[idx]>=0)
    ans=max(ans,func(idx-1,wt_left-wt[idx])+val[idx]);
    return dp[idx][wt_left]=ans;
}
void solve()
{
  memset(dp,-1,sizeof(dp));
  int n,w;
  cin>>n>>w;
  for(int i=0; i<n; i++)
  {
      cin>>wt[i]>>val[i];
  }
  cout<<func(n-1,w);
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

