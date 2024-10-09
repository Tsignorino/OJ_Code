#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;

    map<ll, ll> mp;
    for (int i = 0; i < n; ++i) {
        int s, c;
        cin >> s >> c;
        mp[s] += c;
    }

    ll ans = 0;
    while (!mp.empty()) {
        auto [v, c] = *mp.begin();
        mp.erase(mp.begin());
        ans += c % 2;
        if (c >= 2) {
            mp[v * 2] += c / 2;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}