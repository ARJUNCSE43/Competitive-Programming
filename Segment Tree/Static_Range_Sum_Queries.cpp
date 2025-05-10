#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<ll> a(n + 1, 0);       // 1-based indexing
    vector<ll> prefix_sum(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        prefix_sum[i] = prefix_sum[i - 1] + a[i];
    }

    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << prefix_sum[b] - prefix_sum[a - 1] << '\n';
    }

    return 0;
}
