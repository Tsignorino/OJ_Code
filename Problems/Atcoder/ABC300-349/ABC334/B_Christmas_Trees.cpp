#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    ll a, m, l, r;
    cin >> a >> m >> l >> r;

    ll c1 = abs(l - a) / m;
    ll c2 = abs(r - a) / m;
    // cout << c1 << " " << c2 << "\n";

    if (r <= a) {
        cout << c1 - c2 + ((r - a) % m == 0) << "\n";
    } else if (l >= a) {
        cout << c2 - c1 + ((l - a) % m == 0) << "\n";
    } else {
        cout << c1 + c2 + 1 << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}