#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

// https://codeforces.com/gym/105104/problem/B

void solve() {
    ll x_, y_, z_, k_, d_;
    cin >> x_ >> y_ >> z_ >> k_ >> d_;

    __int128 x = x_, y = y_, z = z_, k = k_, d = d_;

    if (x * y >= z) {
        cout << 0 << "\n";
        return;
    }

    ll ans = 0;
    if (x < y) {
        swap(x, y);
    }
    if (x * k < x + d || x * k == x + d && y * k > y + d) { // 先加再乘
        x += d;
        y *= k;
        ans++;
    }
    while (x * y < z) {
        x *= k;
        y += d;
        ans += 1;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
