#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5 + 5;
const ll INF=1e18;
ll a[N];
struct Node{
  ll mn;
  int cnt;
    
}t[N * 4];

Node combine(Node a, Node b)
{
    if(a.mn<b.mn)return a;
    if(b.mn<a.mn)return b;
    return {a.mn,a.cnt+b.cnt};
}

void build(int node, int b, int e) {
    if (b == e) {
        t[node] = {a[b],1};
        return;
    }
    int mid = (b + e) / 2;
    int l=2*node, r=node*2+1;
    build(l, b, mid);
    build(r, mid + 1, e);
    t[node] = combine(t[l], t[r]);
}

Node query(int node, int b, int e, int l, int r) {
    if (r < b || l > e) return {INF ,0};
    if (l <= b && e <= r) return t[node];
    int mid = (b + e) / 2;
    Node left = query(2 * node, b, mid, l, r);
    Node right = query(2 * node + 1, mid + 1, e, l, r);
    return combine(left, right);
}

void update(int node, int b, int e, int idx, ll val) {
    if (idx < b || idx > e) return;
    if (b == e) {
        t[node] = {val,1};
        return;
    }
    int mid = (b + e) / 2;
    int l=2*node, r=node*2+1;
    update(2 * node, b, mid, idx, val);
    update(2 * node + 1, mid + 1, e, idx, val);
    t[node] = combine(t[l], t[r]);
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
        ll y;
        cin >> type >> x >> y;
        if (type == 1) {
            update(1, 0, n - 1, x, y);
        } else if (type == 2) {
             Node ans=query(1, 0, n - 1, x, y - 1);
             cout<<ans.mn<<" "<<ans.cnt<<endl;

        }
    }

    return 0;
}
