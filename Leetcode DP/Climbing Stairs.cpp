#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

const int MOD=1e9+7;
int gcd(int a,int b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
int lcm(int a,int b){return (a*b/gcd(a,b));}
int int_pow(int base, int exp) {
    int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) result *= base;
        base *= base;
        exp /= 2;
    }
    return result;
}

void coprime(int n)
{
    vector<int>f;
    for(int i=2; i*i<=n; i++)
    {
        while(n%i==0)
        {
            f.pb(i);
            n/=i;
        }

    }
    if(n>1)f.pb(n);
    //for(auto &x:f){cout<<x<<" ";}
    map<int,int>mp;
    for(auto &x:f){
        mp[x]++;
    }
    int cnt=1;
    for(auto &x:mp)
    {
       cnt *= int_pow(x.first, x.second - 1) * (x.first - 1);
    }
    cout<<cnt<<endl;

}
int main() {


  int n;
  cin>>n;
  vector<double>v(n);
  for(auto &x:v){cin>>x;}
  vector<vector<double>>dp(n+1,vector<double>(n+1,0.0));
  dp[0][0]=1.0;
  for(int i=1; i<=n; i++)
  {
      for(int j=0; j<=i; j++)
      {
          dp[i][j]+=dp[i-1][j]*(1-v[i-1]);
          if(j>0){
            dp[i][j]+=dp[i-1][j-1]*(v[i-1]);
          }

      }
  }
  double ans=0.0;
  for(int j=(n+1)/2; j<=n; j++)
  {
      ans+=dp[n][j];
  }
  cout<<fixed<<setprecision(10)<<ans<<"\n";



}
