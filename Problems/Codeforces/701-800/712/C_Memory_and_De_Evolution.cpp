#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int x, y;
    cin >> x >> y;

    int a = y, b = y;
    int ans = 0;
    while (a < x) {
        tie(a, b) = pair(a + b - 1, a);
        ans++;
    }
    ans += 2;
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}