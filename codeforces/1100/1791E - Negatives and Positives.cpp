#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    long long total_abs_sum = 0;
    long long min_abs = LLONG_MAX;
    int neg_count = 0;

    for (int i = 0; i < n; ++i) {
        long long x;
        cin >> x;
        if (x < 0) {
            ++neg_count;
        }
        long long abs_x = abs(x);
        total_abs_sum += abs_x;
        min_abs = min(min_abs, abs_x);
    }

    if (neg_count % 2 == 0) {
        cout << total_abs_sum << '\n';
    } else {
        cout << total_abs_sum - 2 * min_abs << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}