#include <bits/stdc++.h>
#define ll long long 
using namespace std;
const int N=1e5+7;
const int INF=1e9+7;
ll a[N];
ll sum[4*N],prefix[4*N],suffix[4*N],maxSum[4*N];
void build(int node,int b,int e)
{
    if(b==e)
    {
        sum[node]=a[b];
        prefix[node]=suffix[node]=maxSum[node]=max(0LL,a[b]);
        return;
    }
    int mid=(b+e)>>1;
    int l=2*node, r=2*node+1;
    build(l,b,mid);
    build(r,mid+1,e);
    sum[node]=sum[l]+sum[r];
    prefix[node]=max(prefix[l],sum[l]+prefix[r]);
    suffix[node]=max(suffix[r], sum[r]+suffix[l]);
    maxSum[node]=max({maxSum[l], maxSum[r],suffix[l]+prefix[r]});

}
void update(int node, int b, int e, int pos, ll val) {
    if (b==e) {
        sum[node]=val;
        prefix[node]=suffix[node]=maxSum[node]=max(0LL,val);
        return;
    } 
    int mid=(b+e)>>1;
     int l=2*node, r=2*node+1;
    if(pos<=mid){
       
        update(l,b,mid,pos,val);
    }
    else{
        update(r,mid+1,e,pos,val);
    }
    sum[node]=sum[l]+sum[r];
    prefix[node]=max(prefix[l],sum[l]+prefix[r]);
    suffix[node]=max(suffix[r], sum[r]+suffix[l]);
    maxSum[node]=max({maxSum[l], maxSum[r],suffix[l]+prefix[r]});
}

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        
    }
    build(1,0,n-1);
    cout<<maxSum[1]<<endl;
    while(m--)
    {
        int idx;
        ll val;
        cin>>idx>>val;
        update(1,0,n-1,idx,val);
        cout<<maxSum[1]<<endl;
    }
}