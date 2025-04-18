#include<bits/stdc++.h>
#define vi vector<int>
#define ll long long

using namespace std;
ll ans=0;
ll N,W;
void dfs(ll id,ll curW,ll cur,vector<ll>&v,vector<ll>&w)
{
    if(curW>W)return;
    if(id==W)
    {
        ans=max(ans,cur);return;
    }
    dfs(id+1,W,cur,v,w);
    dfs(id+1,W+w[id],cur+v[id],v,w);
}
void solve()
{

  cin>>N>>W;
  vector<ll>w(N);
  vector<ll>v(N);
  for(int i=0; i<N; i++)
  {

      cin>>w[i]>>v[i];
  }
  ans=0;
  dfs(0,0,0,v,w);
  cout<<ans<<endl;
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
