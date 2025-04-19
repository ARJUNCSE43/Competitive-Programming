#include<bits/stdc++.h>
#define vi vector<int>
#define ll long long
const ll INF=1e18;
using namespace std;
void solve()
{
    ll n,W;
    cin>>n>>W;
    vector<ll>wt(n),val(n);
    ll totalvalue=0;
    for(int i=0; i<n; i++)
    {
        cin>>wt[i]>>val[i];
        totalvalue+=val[i];
    }
    vector<ll>dp(totalvalue+1,INF);
    dp[0]=0;
    for(ll i=0; i<n; i++)
    {
        for(ll k=totalvalue; k>=val[i]; k--)
        {
            dp[k]=min(dp[k],dp[k-val[i]]+wt[i]);
        }
    }
    ll ans=0;
    for(int k=0; k<=totalvalue; k++)
    {
        if(dp[k]<=W)
        {
            ans=k;
        }
    }
cout<<ans<<endl;


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
