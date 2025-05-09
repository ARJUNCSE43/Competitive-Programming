#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
const int p1=911, p2=3571,mod1=1e9+7,mod2=1e9+9;
const int N=1e6+5;
int pw1[N],pw2[N], h1[N],h2[N];

void pre()
{
    pw1[0]=pw2[0]=1;
    for(int i=1; i<N; i++)
    {
        pw1[i]=1LL* pw1[i-1]*p1%mod1;
        pw2[i]=1LL* pw2[i-1]*p2%mod2;
    }
}
void build_hash(string& s)
{
    int n=s.size();
    for(int i=0; i<n; i++)
    {
        h1[i+1]=(h1[i]+1LL*s[i]*pw1[i]%mod1)%mod1;
        h2[i+1]=(h2[i]+1LL*s[i]*pw2[i]%mod2)%mod2;
    }
}
// get hash of substring s[l..r];
pair<int,int>get_sub_hash(int l,int r)
{
    int x1=(h1[r+1]-h1[l]+mod1)%mod1;
    x1=1LL*x1*pw1[N-1-l]%mod1;
    
    int x2=(h2[r+1]-h2[l]+mod2)%mod2;
    x2=1LL*x2*pw2[N-l-1]%mod2;

    return {x1,x2};
}
int main()
{
     
     ios::sync_with_stdio(false);
     cin.tie(NULL);
     pre();
     string s;
     cin>>s;
     int n=s.size();
     build_hash(s);
     vector<int>borders;
     for(int i=1; i<n; i++)
     {
        auto prefix_hash=get_sub_hash(0,i-1);
        auto suffix_hash=get_sub_hash(n-i,n-1);
        if(prefix_hash==suffix_hash)
        {
            borders.push_back(i);
        }
     }
     for(auto &x:borders)
     {
        cout<<x<<" ";
     }
}
