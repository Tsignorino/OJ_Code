#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> vec(n);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }

    int mx = ranges::max(vec);

    vector<int> res(n);
    for (int i = 0; i < n; ++i) {
        res[i] = (mx - vec[i]) % (2 * k);
    }

    // map<int, int> mp;
    // for (int& v : res) {
    //     mp[v]++;
    // }
    // for (auto& [v, _] : mp) {
    //     if (mp.contains(v + k)) {
    //         cout << -1 << "\n";
    //         return;
    //     }
    // }

    // if (ranges::max(res) < k) {
    //     cout << mx << "\n";
    //     return;
    // }

    // for (int i = 0; i < n; ++i) {
    //     cout << res[i] << " ";
    // }
    // cout << "\n";

    vector<pair<int, int>> t; // 闭区间
    for (int& v : res) {
        if (v < k) {
            t.emplace_back(0, k - 1 - v);
        } else {
            t.emplace_back(2 * k - v, 3 * k - v - 1);
        }
    }

    ranges::sort(t);
    // for (auto& [s, e] : t) {
    //     cout << s << " " << e << "; ";
    // }
    // cout << "\n";

    auto [l, r] = t[0];
    for (auto& [fi, se] : t) {
        if (fi > r) {
            cout << -1 << "\n";
            return;
        }
        l = max(l, fi), r = min(r, se);
    }
    // if (l > r) {
    //     cout << -1 << "\n";
    //     return;
    // }

    cout << mx + l << "\n";
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