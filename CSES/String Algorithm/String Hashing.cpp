#include <bits/stdc++.h>
using namespace std;

const int p1 = 911, mod1 = 1e9 + 7;
const int p2 = 3571, mod2 = 1e9 + 9;
const int N = 1e6 + 5; // Max string length + buffer

int pw1[N], pw2[N];         // Power arrays
int pw1_inv[N], pw2_inv[N]; // Inverse power arrays
int h1[N], h2[N];           // Prefix hashes

// Fast exponentiation (a^b mod m)
int mod_pow(int a, int b, int mod) {
    int res = 1;
    while (b) {
        if (b & 1) res = 1LL * res * a % mod;
        a = 1LL * a * a % mod;
        b >>= 1;
    }
    return res;
}

// Precompute powers and inverse powers
void pre() {
    pw1[0] = pw2[0] = 1;
    for (int i = 1; i < N; i++) {
        pw1[i] = 1LL * pw1[i - 1] * p1 % mod1;
        pw2[i] = 1LL * pw2[i - 1] * p2 % mod2;
    }
    int inv_p1 = mod_pow(p1, mod1 - 2, mod1);
    int inv_p2 = mod_pow(p2, mod2 - 2, mod2);
    pw1_inv[0] = pw2_inv[0] = 1;
    for (int i = 1; i < N; i++) {
        pw1_inv[i] = 1LL * pw1_inv[i - 1] * inv_p1 % mod1;
        pw2_inv[i] = 1LL * pw2_inv[i - 1] * inv_p2 % mod2;
    }
}

// Build prefix hashes of string s
void build_hash(const string& s) {
    int n = s.size();
    for (int i = 0; i < n; i++) {
        h1[i + 1] = (h1[i] + 1LL * s[i] * pw1[i] % mod1) % mod1;
        h2[i + 1] = (h2[i] + 1LL * s[i] * pw2[i] % mod2) % mod2;
    }
}

// Get hash of substring s[l..r]
pair<int, int> get_sub_hash(int l, int r) {
    int x1 = (h1[r + 1] - h1[l] + mod1) % mod1;
    x1 = 1LL * x1 * pw1_inv[l] % mod1;

    int x2 = (h2[r + 1] - h2[l] + mod2) % mod2;
    x2 = 1LL * x2 * pw2_inv[l] % mod2;

    return {x1, x2};
}

// Compute the hash of a full string
pair<int, int> get_hash(const string& s) {
    int hs1 = 0, hs2 = 0;
    for (int i = 0; i < s.size(); i++) {
        hs1 = (hs1 + 1LL * s[i] * pw1[i] % mod1) % mod1;
        hs2 = (hs2 + 1LL * s[i] * pw2[i] % mod2) % mod2;
    }
    return {hs1, hs2};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    pre();

    string s, pattern;
    cin >> s >> pattern;

    int n = s.size(), m = pattern.size();

    build_hash(s); // Build prefix hashes for the main string
    auto pat_hash = get_hash(pattern); // Get hash of pattern

    int count = 0;
    for (int i = 0; i + m - 1 < n; i++) {
        auto cur_hash = get_sub_hash(i, i + m - 1);
        if (cur_hash == pat_hash) {
            count++;
        }
    }

    cout << count << "\n";

    return 0;
}
