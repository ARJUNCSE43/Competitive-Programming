#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5 + 5;
ll a[N];
ll t[N * 4];

void build(int node, int b, int e) {
    if (b == e) {
        t[node] = a[b];
        return;
    }
    int mid = (b + e) / 2;
    build(2 * node, b, mid);
    build(2 * node + 1, mid + 1, e);
    t[node] = (t[2 * node]^t[2 * node + 1]);
}

ll query(int node, int b, int e, int l, int r) {
    if (r < b || l > e) return 0;
    if (l <= b && e <= r) return t[node];
    int mid = (b + e) / 2;
    ll left = query(2 * node, b, mid, l, r);
    ll right = query(2 * node + 1, mid + 1, e, l, r);
    return (left^right);
}

void update(int node, int b, int e, int idx, ll val) {
    if (idx < b || idx > e) return;
    if (b == e) {
        t[node] = val;
        return;
    }
    int mid = (b + e) / 2;
    update(2 * node, b, mid, idx, val);
    update(2 * node + 1, mid + 1, e, idx, val);
    t[node] = (t[2 * node]^t[2 * node + 1]);
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
        int x,y;
        cin>>x>>y;
        x--;y--;
        cout<<query(1,0,n-1,x,y)<<endl;
       
    }

    return 0;
}
