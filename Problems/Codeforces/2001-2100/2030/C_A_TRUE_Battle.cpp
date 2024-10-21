#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            v[i] = 1;
        }
    }

    bool win = false;
    if (v[0] || v[n - 1]) {
        win = true;
    }
    for (int i = 1; i < n; i++) {
        if (v[i] && v[i - 1]) {
            win = true;
        }
    }
    cout << (win ? "YES" : "NO") << "\n";
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