#include <bits/stdc++.h>
#define ll long long 
using namespace std;
const int N=1e5+7;
const int INF=1e9+7;
ll a[N];
pair<int,int>tree[4*N];

pair<int,int>combine(pair<int,int>a, pair<int,int>b)
{
    if(a.first<b.first)
        return a;
    if(b.first<a.first)
        return b;
    return make_pair(a.first,a.second+b.second);
}

void build(int node,int st,int ed)
{

   if(st==ed)
   {
    tree[node]={a[st],1};return;
   }
   int l=2*node, r=2*node+1;
   int mid=(st+ed)>>1;
   build(l,st,mid);
   build(r,mid+1,ed);
   tree[node]=combine(tree[l],tree[r]);

}

pair<int,int>get_min(int node,int st,int ed,int i,int j)
{
   if(i>j)return {INF,0};
   if(i==st && ed==j)
   {
    return tree[node];
   }
   int l=2*node, r=node*2+1;
   int mid=(st+ed)>>1;
   return combine(
     get_min(l,st,mid,i,min(mid,j)),
     get_min(r,mid+1,ed,max(i,mid+1),j)
    );
}
void update(int node, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        tree[node] = {new_val, 1};
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(node*2, tl, tm, pos, new_val);
        else
            update(node*2+1, tm+1, tr, pos, new_val);
        tree[node] = combine(tree[node*2], tree[node*2+1]);
    }
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
    while(m--)
    {
        int t,x,y;
        cin>>t>>x>>y;
        if(t==1)
        {
           update(1,0,n-1,x,y);
        }
        else
        {
            pair<int,int>res=get_min(1,0,n-1,x,y-1);
            cout<<res.first<<" "<<res.second<<endl;
        }
    }
}