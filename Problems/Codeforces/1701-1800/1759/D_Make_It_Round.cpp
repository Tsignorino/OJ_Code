#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

void solve() {
    ll n, m;
    cin >> n >> m;

    int ans = 0;
    while (n % 10 == 0) {
        ans++;
        n /= 10;
    }
    while (n % 2 == 0 && m >= 5) {
        n /= 2;
        m /= 5;
        ans++;
    }
    while (n % 5 == 0 && m >= 2) {
        n /= 5;
        m /= 2;
        ans++;
    }
    while (m > 10) {
        m /= 10;
        ans++;
    }

    cout << n * m;
    while (ans--) {
        cout << 0;
    }
    cout << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(20);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
