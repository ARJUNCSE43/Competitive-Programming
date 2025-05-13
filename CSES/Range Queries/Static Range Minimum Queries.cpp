#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+7;
ll ar[N];
ll tree[N*4];

void build(int node, int b, int e) {
    if (b == e) {
        tree[node] = ar[b];
        return;
    }
    int mid = (b + e) / 2;
    int l=2*node, r=2*node+1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[node] = min(tree[l], tree[r]);
}


ll query(int node,int b,int e,int i,int j)
{
	if(b>j|| e<i)return LLONG_MAX;
	if(i<=b && e<=j)return tree[node];
	int mid=(b+e)>>1;
	int l=2*node, r=2*node+1;
	ll left=query(l,b,mid,i,j);
	ll right=query(r,mid+1,e,i,j);
	return min(left,right);
}
int main()
{

	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> ar[i];

    build(1, 0, n - 1);
    while(m--)
    {
    	int x,y;
    	cin>>x>>y;
    	x--,y--;
    	cout<<query(1,0,n-1,x,y)<<"\n";
    }
}
