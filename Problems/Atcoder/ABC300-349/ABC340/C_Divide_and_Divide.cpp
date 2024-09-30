#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    ll n;
    cin >> n;

    map<ll, ll> mp;
    mp[n] = 1;

    ll ans = 0;
    while (true) {
        auto [x, c] = *mp.rbegin();
        mp.erase(prev(mp.end()));

        if (x == 1) {
            break;
        }
        ans += x * c;
        mp[x / 2] += c;
        mp[(x + 1) / 2] += c;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}