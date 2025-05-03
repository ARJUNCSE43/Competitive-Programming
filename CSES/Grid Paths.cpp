
#include<bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
int ways(int i,int j,vector<vector<int>>&dp,vector<vector<char>>&grid)
{

    if(i<0 || j<0)return 0;
    if(i>=0 && j>=0 && grid[i][j]=='*')return 0;
    if(i==0 && j==0)return 1;
    if(dp[i][j]!=-1)return dp[i][j];
    int up=ways(i-1,j,dp,grid);
    int left=ways(i,j-1,dp,grid);
    return dp[i][j]=(up+left)%MOD;
}
int main()
{

    int t=1;
    //cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<char>>grid(n,vector<char>(n,0));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cin>>grid[i][j];
            }
        }
       vector<vector<int>>dp(n,vector<int>(n,-1));
       cout<<ways(n-1,n-1,dp,grid);


    }
}
