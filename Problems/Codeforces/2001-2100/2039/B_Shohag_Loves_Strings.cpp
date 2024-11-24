// Date: 2024-11-24  星期天

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    string s;
    cin >> s;

    int n = s.size();
    if (n == 1) {
        cout << -1 << "\n";
        return;
    }

    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == s[i + 1]) {
            cout << s.substr(i, 2) << "\n";
            return;
        }
    }
    for (int i = 0; i < n - 2; i++) {
        if (s[i] != s[i + 2]) {
            cout << s.substr(i, 3) << "\n";
            return;
        }
    }
    cout << -1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}