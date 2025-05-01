#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

class Solution {
public:
   int solve(vector<vector<int>>&v,vector<vector<int>>&dp,int i, int j)
   {
      if(i>=0 && j>=0 && v[i][j]==1)return 0;
      if(i==0 && j==0)return 1;
      if(i<0 || j<0)return 0;
      if(dp[i][j]!=-1)return dp[i][j];
      int up=solve(v,dp,i-1 , j);
      int left=solve(v,dp,i,j-1);
      return dp[i][j]=up+left;
   }
    int uniquePathsWithObstacles(vector<vector<int>>& Grid) {

    int n=Grid.size();
    int m=Grid[0].size();
    vector<vector<int>>dp(n,vector<int>(m,-1));
    return solve(Grid,dp,n-1,m-1);


    }
};
int main() {

  int  t;
  cin>>t;
  while(t--)
  {
      Solution obj;
      int m,n;
      cin>>m>>n;
      vector<vector<int>>grid(m,vector<int>(n));
      for(int i=0; i<m; i++)
      {
          for(int j=0; j<n; j++)
          {
              cin>>grid[i][j];
          }
      }
      cout<<obj.uniquePathsWithObstacles(grid);

  }

}
