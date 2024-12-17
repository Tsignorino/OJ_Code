// Date: 2024-12-16  星期一

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

void solve() {
    string s;
    cin >> s;

    int n = s.size();
    ll ans = 0;
    for (int l = 0; l < n; ++l) {
        int r = l;
        while (r < n - 1 && s[r] != s[r + 1]) {
            r++;
        }
        if (r > l) {
            ans += (r - l + 1) * 1ll * (r - l) / 2;
        }
        l = r;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}