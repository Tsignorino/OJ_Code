#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

static constexpr int MOD = 1e9 + 7;

/*
    0 < y < x  and  0 < (x ^ y) < x, then, x -> y or x -> x ^ y
*/

void solve() {
    ll n, m;
    cin >> n >> m;
    if ((n ^ m) < n) {
        cout << 1 << "\n";
        cout << n << " " << m << "\n";
        return;
    }

    ull hb = 1ll << (bit_width(ull(n)) - 1);
    ll x = (1ll << bit_width(hb ^ n)) - 1; // 将次高位到最低位全变为 1
    if (x < m) {
        cout << -1 << "\n";
    } else {
        cout << 2 << "\n";
        cout << n << " " << x << " " << m << "\n";
    }
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