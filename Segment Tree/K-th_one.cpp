#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5 + 5;
ll a[N];
ll t[N * 4];

void build(int node, int b, int e) {
    if (b == e) {
        t[node] = a[b];

        
    }
    else{
    int mid = (b + e) / 2;
    build(2 * node, b, mid);
    build(2 * node + 1, mid + 1, e);
    t[node] = t[2 * node]+t[2 * node + 1];
  }
}

ll query(int node, int b, int e, int k) {
   if(b==e)return b;
   int mid=(b+e)>>1;
   if(t[2*node]>k)return query(2*node,b,mid,k);
   else return query(2*node+1,mid+1,e,k-t[2*node]);
}

void update(int node, int b, int e, int i) {
    
    if (b == e) {
        a[i]^=1;
        t[node] = a[i];
        
    
    }
    else{
        int mid = (b + e) / 2;
        if(i<=mid)update(2 * node, b, mid,i);
        else update(2 * node + 1, mid + 1, e, i);
        t[node] =(t[2 * node]+ t[2 * node + 1]);
     }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    build(1, 0, n - 1);

    while (m--) {
        int type, x;
        cin>>type>>x;
        if(type==1)
        {
            update(1,0,n-1,x);
        }
        else
        {
            cout<<query(1,0,n-1,x)<<endl;
        }
    }

    return 0;
}