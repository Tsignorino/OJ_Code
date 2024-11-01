#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;

    if (n == 1 || n == 3) {
        cout << -1 << "\n";
        return;
    }

    string ans("66");
    n -= 2;
    if (n & 1) {
        ans += "363";
        n -= 3;
    }
    ans += string(n, '3');

    ranges::reverse(ans);
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