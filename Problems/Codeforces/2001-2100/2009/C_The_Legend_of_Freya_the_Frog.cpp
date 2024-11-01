#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int x, y, k;
    cin >> x >> y >> k;

    int c1 = (x + k - 1) / k, c2 = (y + k - 1) / k;
    cout << max(c1, c2) * 2 - (c1 > c2) << "\n";
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