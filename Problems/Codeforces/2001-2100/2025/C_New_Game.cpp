#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

// #include "_debug.h"

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> vec(n);
    map<int, int> mp;
    for (int& v : vec) {
        cin >> v;
        mp[v]++;
    }

    // ranges::sort(vec);
    // debug(vec);

    vector<vector<int>> res;
    int pre = -1;
    for (auto& [v, c] : mp) {
        if (res.empty() || pre != -1 && v > pre + 1) {
            res.emplace_back(vector<int>());
        }
        res.back().emplace_back(c);
        pre = v;
    }

    // debug(ans);

    int ans = 0;
    for (auto& a : res) {
        if (a.size() <= k) {
            ans = max(ans, accumulate(a.begin(), a.end(), 0));
            continue;
        }

        int res = accumulate(a.begin(), a.begin() + k, 0);
        ans = max(ans, res);
        for (int i = k; i < a.size(); ++i) {
            res += a[i];
            res -= a[i - k];
            ans = max(ans, res);
        }
    }
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