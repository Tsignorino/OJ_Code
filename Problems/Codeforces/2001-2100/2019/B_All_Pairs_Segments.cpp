#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// #include "_debug.h"

static constexpr int MOD = 1'000'000'007;

void solve() {
    ll n, q;
    cin >> n >> q;

    vector<ll> vec(n);
    for (ll& v : vec) {
        cin >> v;
    }

    ranges::sort(vec);

    map<ll, ll> mp;
    for (ll i = 0; i < n; ++i) {
        mp[vec[i]] += n - i - 1;
        mp[vec[i] + 1] -= i;
    }

    // debug(mp);

    ll pre = 0;
    map<ll, ll> C;
    for (auto& [v, c] : mp) {
        C[v] = c + pre;
        pre += c;
    }

    // debug(C);

    map<ll, ll> Cnt;
    for (auto iter = C.begin(); iter != C.end(); ++iter) {
        if (next(iter) == C.end()) {
            break;
        }
        Cnt[iter->second] += next(iter)->first - iter->first;
    }

    // debug(Cnt);

    while (q--) {
        ll v;
        cin >> v;

        cout << Cnt[v] << " ";
    }
    cout << "\n";
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