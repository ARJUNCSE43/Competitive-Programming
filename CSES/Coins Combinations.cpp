#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;
vector<int> dp;

int solve(int x, vector<int>& coins) {
    if (x == 0) return 1;
    if (dp[x] != -1) return dp[x];

    int ways = 0;
    for (int coin : coins) {
        if (coin <= x)
            ways = (ways + solve(x - coin, coins)) % MOD;
    }

    return dp[x] = ways;
}


int main() {
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (auto &c : coins) cin >> c;

    dp.assign(x + 1, -1);
    cout << solve( x, coins) << endl;

    return 0;
}
