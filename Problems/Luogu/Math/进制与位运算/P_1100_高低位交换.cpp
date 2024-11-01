#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

// #include "_debug.h"

void solve() {
    ll n;
    cin >> n;

    auto s = bitset<32>(n).to_string();
    auto t = s.substr(16, 16) + s.substr(0, 16);
    // debug(s);
    // debug(t);

    ll ans = 0;
    for (int i = 0; i < 32; ++i) {
        ans += (t[i] - '0') * (1ll << (31 - i));
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}