#include<bits/stdc++.h>
using namespace std;
int main()
{

    int t=1;
    //cin>>t;
    while(t--)
    {
        int n;

        cin>>n;
        vector<int>dp(n+1,INT_MAX);
        dp[0]=0;  // base case
        for(int i=1; i<=n; i++)
        {
            int x=i;
            while(x>0)
            {
                int d=x%10;
                x/=10;
                if(d==0)continue;
                dp[i]=min(dp[i],dp[i-d]+1);
            }
        }
        cout<<dp[n]<<endl;

    }
}
