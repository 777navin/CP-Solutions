#include <bits/stdc++.h>
using namespace std;

static constexpr int MOD = 1'000'000'007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    if (!(cin >> n >> k)) return 0;

    vector<int> dp(n + 1, 1);
    dp[0] = 0;

    for (int len = 1; len < k; ++len) {
        vector<int> next_dp(n + 1, 0);
        for (int x = 1; x <= n; ++x) {
            if (dp[x] == 0) continue;
            for (int mult = x; mult <= n; mult += x) {
                next_dp[mult] += dp[x];
                if (next_dp[mult] >= MOD) {
                    next_dp[mult] -= MOD;
                }
            }
        }
        dp.swap(next_dp);
    }

    long long ans = 0;
    for (int x = 1; x <= n; ++x) {
        ans += dp[x];
    }
    ans %= MOD;

    cout << ans << '\n';
    return 0;
}