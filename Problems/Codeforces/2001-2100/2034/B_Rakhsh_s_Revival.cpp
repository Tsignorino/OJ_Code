// Date: 2024-12-01  星期天

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    string s;
    cin >> s;

    int ans = 0, cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            cnt++;
            if (cnt == m) {
                ans++;
                i += k - 1;
                cnt = 0;
            }
        } else {
            cnt = 0;
        }
    }
    cout << ans << "\n";
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