#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

class Solution {
public:
    int solve(int n,vector<int>&memo)
    {
      if(n<=2)return n;
      if(memo[n]!=-1)return memo[n];
      return memo[n]=solve(n-1,memo)+solve(n-2,memo);

    }
    int climbStairs(int n) {
        vector<int>dp(n+1,0);
        if(n<=2)return n;
        dp[1]=1;
        dp[2]=2;

        for(int i=3; i<=n; i++)
        {
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};

int main() {

    Solution obj;

    int n;
    cin>>n;
    cout<<obj.climbStairs(n)<<endl;

}
