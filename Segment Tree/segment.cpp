#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=1e5+9;
ll a[N];
ll t[N*4];


void build(int node,int b,int e)
{
    if(b==e)
    {
        t[node]=a[b];
        return;
    }
    int l=2*node, r=2*node+1;
    int mid=(b+e)/2;
    build(l,b,mid);
    build(r,mid+1,e);

    t[node]=t[l]+t[r];
}
ll query(int node,int b, int e, int i, int j)
{

    if(i>e || j<b)
    {
        return 0;
    }
    if(b>=i && e<=j)
    {
        return t[node];
    }
    int l=node*2;
    int r=node*2+1;
    int mid=(b+e)/2;

    ll p1=query(l,b,mid,i,j);
    ll p2=query(r,mid+1,e,i,j);

    return p1+p2;
}

void update(int node,int b, int e, int i,ll val)
{
	if(i>e || i<b)
	{
		return;
	}
	if(b==e)
	{
		t[node]=val;
		return;
	}
	int l=node*2, r=node*2+1;
    int mid=(b+e)/2;
    update(l,b,mid,i,val);
    update(r,mid+1,e,i,val);
    t[node]=t[l]+t[r];
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

        int q,x,y;
        cin>>q>>x>>y;
        if(q==1)
        {

            update(1,0,n-1,x,y);
        }
        else if(q==2)
        {
             cout<<query(1,0,n-1,x,y-1)<<endl;
             
        }

    }    

}
