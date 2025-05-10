#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5 + 5;

struct Node {
    ll sum, lazy;
} tree[4 * N];

ll a[N];

void build(int node, int l, int r) {
    if (l == r) {
        tree[node].sum = a[l];
        tree[node].lazy = 0;
        return;
    }
    int mid = (l + r) / 2;
    build(2 * node, l, mid);
    build(2 * node + 1, mid + 1, r);
    tree[node].sum = tree[2 * node].sum + tree[2 * node + 1].sum;
    tree[node].lazy = 0;
}

void propagate(int node, int l, int r) {
    if (tree[node].lazy != 0) {
        tree[node].sum += (r - l + 1) * tree[node].lazy;
        if (l != r) {
            tree[2 * node].lazy += tree[node].lazy;
            tree[2 * node + 1].lazy += tree[node].lazy;
        }
        tree[node].lazy = 0;
    }
}

void update(int node, int l, int r, int ql, int qr, ll val) {
    propagate(node, l, r);
    if (r < ql || l > qr) return;
    if (ql <= l && r <= qr) {
        tree[node].lazy += val;
        propagate(node, l, r);
        return;
    }
    int mid = (l + r) / 2;
    update(2 * node, l, mid, ql, qr, val);
    update(2 * node + 1, mid + 1, r, ql, qr, val);
    tree[node].sum = tree[2 * node].sum + tree[2 * node + 1].sum;
}

ll query(int node, int l, int r, int ql, int qr) {
    propagate(node, l, r);
    if (r < ql || l > qr) return 0;
    if (ql <= l && r <= qr) return tree[node].sum;
    int mid = (l + r) / 2;
    return query(2 * node, l, mid, ql, qr) + query(2 * node + 1, mid + 1, r, ql, qr);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    for (int i = 0; i < n; ++i)
        cin >> a[i];

    build(1, 0, n - 1);

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r;
            ll x;
            cin >> l >> r >> x;
            l--, r--; // 0-based
            update(1, 0, n - 1, l, r, x);
        } else if (type == 2) {
            int k;
            cin>>k;
            k--;
            cout << query(1, 0, n - 1,k,k) << '\n';
        }
    }

    return 0;
}
