#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;

    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    int g = ranges::min(vec); // Take the minimum value as the first term
    map<int, int> mp;
    mp[g] = -1;
    int __gcd = 0; // all elements' gcd
    for (int i = 0; i < n; ++i) {
        mp[gcd(g, vec[i])]++;
        __gcd = gcd(__gcd, vec[i]);
    }

    ll ans = g;
    int k = 1;
    while (g > __gcd) {
        int mn = numeric_limits<int>::max();
        map<int, int> tmp;
        for (auto& [x, c] : mp) {
            int v = gcd(x, g);
            tmp[v] += c;
            mn = min(mn, v);
        }

        g = mn;
        ans += g;
        k++;
        tmp[g]--;

        mp = std::move(tmp);
    }
    ans += __gcd * 1ll * (n - k);

    cout << ans << "\n";
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