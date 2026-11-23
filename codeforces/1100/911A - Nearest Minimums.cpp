#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long min_val = LLONG_MAX;
    int last_idx = -1;
    int ans = INT_MAX;

    for (int i = 0; i < n; ++i) {
        if (a[i] < min_val) {
            min_val = a[i];
            last_idx = i;
            ans = INT_MAX;
        } else if (a[i] == min_val) {
            if (last_idx != -1) {
                ans = min(ans, i - last_idx);
            }
            last_idx = i;
        }
    }

    cout << ans << '\n';
    return 0;
}