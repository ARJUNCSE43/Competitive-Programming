#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    ll n,q;
    cin>>n>>q;
    vector<ll>v(n);
    for(auto &x:v){cin>>x;}
    vector<ll>prefix(n),pre(n);
    prefix[0]=v[0];
    for(int i=1; i<n; i++)
    {
        prefix[i]=prefix[i-1]+v[i];
    }
    sort(v.begin(),v.end());
    pre[0]=v[0];
    for(int i=1; i<n; i++)
    {
        pre[i]=pre[i-1]+v[i];
    }

   
    while(q--)
    {
       int x,y;
       cin>>x>>y;
       if(x==1)
        cout<<prefix[y-1]<<endl;
       else cout<<prefix[y-1]-prefix[x-2]<<"\n";
    }
}
int main() {
    int t=1;
    //cin >> t;
    while (t--) {
       solve();
    }
    return 0;
}
