#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;

    if (s == "^") {
        cout << 1 << '\n';
        return;
    }

    int ans = 0;
    if (s.front() == '_') ++ans;
    if (s.back() == '_') ++ans;

    for (size_t i = 1; i < s.size(); ++i) {
        if (s[i] == '_' && s[i - 1] == '_') {
            ++ans;
        }
    }

    cout << ans << '\n';
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