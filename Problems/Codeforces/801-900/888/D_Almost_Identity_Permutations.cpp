#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

ll comb(int x, int y) {
    if (y > x) {
        return 0;
    }
    ll ans = 1;
    for (int i = 0; i < y; i++) {
        ans = ans * (x - i) / (i + 1);
    }
    return ans;
}

void solve() {
    int n, k;
    cin >> n >> k;

    ll ans = 1;
    if (k >= 2) {
        ans += comb(n, 2);
    }
    if (k >= 3) {
        ans += comb(n, 3) * 2;
    }
    if (k >= 4) {
        ans += comb(n, 4) * 9;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}