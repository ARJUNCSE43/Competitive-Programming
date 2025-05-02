#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9;  // safer than INT_MAX

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (auto &c : coins) cin >> c;

   vector<int>dp(x+1,INF);
   dp[0]=0;
   for(int i=0; i<n; i++)
   {
       for(int sum=coins[i]; sum<=x; sum++)
       {
           dp[sum]=min(dp[sum],dp[sum-coins[i]]+1);
       }
   }
   if(dp[x]==INF)cout<<-1<<endl;
   else cout<<dp[x]<<endl;
    return 0;
}
