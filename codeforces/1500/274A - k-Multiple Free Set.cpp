#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long k;
    if (!(cin >> n >> k)) return 0;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    unordered_set<long long> chosen;
    chosen.reserve(n * 2);

    int ans = 0;
    for (long long x : a) {
        if (x % k != 0 || chosen.find(x / k) == chosen.end()) {
            chosen.insert(x);
            ++ans;
        }
    }

    cout << ans << '\n';
    return 0;
}