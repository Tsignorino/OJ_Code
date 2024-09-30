#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

void solve() {
    ll n;
    cin >> n;

    // 按位考虑

    // ll ans = 0;
    // while (n) {
    //     ans += n;
    //     n /= 2;
    // }
    // cout << ans << "\n";

    cout << (n * 2 - __popcount(n)) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
