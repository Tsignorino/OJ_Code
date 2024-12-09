// Date: 2024-12-09  星期一

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    map<char, vector<int>> mp;
    for (int i = 0; i < n; ++i) {
        mp[s[i]].emplace_back(i);
    }

    const int inf = numeric_limits<int>::max();

    int ans = inf;
    for (auto& [_, vec] : mp) {
        int m = vec.size();
        if (m <= 1) {
            continue;
        }
        int res = inf;
        for (int i = 0; i < m; ++i) {
            res = min(res, (vec[(i + 1) % m] - vec[i] - 1 + n) % n);
        }
        ans = min(ans, res);
    }
    if (ans == inf) {
        ans = -1;
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