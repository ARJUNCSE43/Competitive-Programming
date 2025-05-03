

#include<bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    //cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        vector<int>price(n),pages(n);
        for(auto &x:price)
        {
            cin>>x;
        }
        for(auto &x:pages)
        {
            cin>>x;
        }
        vector<int>dp(x+1,0);
        for(int i=0; i<n; i++)
        {
            for(int j=x; j>=price[i]; j--)
            {
                dp[j]=max(dp[j],dp[j-price[i]]+pages[i]);
            }
        }
        cout<<dp[x]<<endl;



    }
}
