#include<bits/stdc++.h>
 using namespace std;
 const int MOD=1e9+7;

//int countWays(int n) {
//    if (n == 0) return 1; // base case
//    if(dp[n]!=-1)return dp[n];
//    int ways = 0;
//    for (int i = 1; i <= 6; i++) {
//        if (n - i >= 0) {
//            ways =(ways+ countWays(n - i))%MOD;
//        }
//    }
//    return dp[n]=ways;
//}
 int main()
 {
     int t=1;
     //cin>>t;
     while(t--)
     {


         int n;
         cin>>n;
          vector<int>dp(n+1,0);
         dp[0]=1; // base case
         for(int i=1; i<=n; i++)
         {
             for(int j=1; j<=6; j++)
             {
                 if(i-j>=0)dp[i]=(dp[i]+dp[i-j])%MOD;
             }
         }
         cout<<dp[n]<<'\n';

     }
 }
