#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    ll n;
    cin >> n;

    ll ans = LLONG_MAX;
    for (int i = 0; i <= 2e6; ++i) {
        ll remain = n - i * 1ll * i;
        ll v = sqrt(remain);
        ans = min(ans, abs(v * v - remain));
        ans = min(ans, abs((v + 1) * (v + 1) - remain));
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}