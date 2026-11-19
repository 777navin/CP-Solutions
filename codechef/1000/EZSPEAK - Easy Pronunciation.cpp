
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        int cnt = 0;
        bool easy = true;

        for (char c : s) {
            if (c == 'a' || c == 'e' || c == 'i' ||
                c == 'o' || c == 'u') {
                cnt = 0;
            } else {
                cnt++;
            }

            if (cnt >= 4) {
                easy = false;
                break;
            }
        }

        cout << (easy ? "YES" : "NO") << '\n';
    }

    return 0;
}
