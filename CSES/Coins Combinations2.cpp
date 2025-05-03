#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int MOD = 1e9 + 7;
vector<vector<int>>dp;
int countWays(int n,int target)
{
    if(target==0)return 1;
    if(target<0 || n==0)return 0;
    if(dp[n][target]!=-1)return dp[n][target];

    int notTake=countWays(n-1,target);
    int Take=0;
    if(target>=n)
    {
        Take=countWays(n-1,target-n);
    }
    return dp[n][target]=(notTake+Take)%MOD;


}
int main() {

  int n;
  cin>>n;
   int total=(n*(n+1))/2;
   if(total%2!=0)
   {
       cout<<0<<endl;return 0;
   }
   int target=total/2;
   dp.assign(n+1,vector<int>(target+1,-1));
   int ways=countWays(n,target);
    int inv=(MOD+1)/2;
    cout<<(1LL*ways*inv)%MOD;

}

