#include<bits/stdc++.h>
#define vi vector<int>
using namespace std;
const int INF=1e9+7;
const int MAXN=1e6;

void solve()
{
    int n;
    cin>>n;
    vector<int>v(n);
    vector<int>dp(n,0);

    for(int i=0; i<n; i++)
    {
        cin>>v[i];
    }
    dp[0]=0;
    dp[1]=abs(v[0]-v[1]);
    for(int i=2; i<n; i++)
    {
        dp[i]=min(dp[i-1]+abs(v[i]-v[i-1]),
                  dp[i-2]+abs(v[i]-v[i-2])
                  );
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
