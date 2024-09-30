#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    string s;
    cin >> s;

    int n = s.size();
    map<char, vector<int>> mp;
    for (int i = 0; i < n; ++i) {
        mp[s[i]].emplace_back(i);
    }

    int m;
    cin >> m;
    string l, r;
    cin >> l >> r;

    int id = -1;
    for (int i = 0; i < m; ++i) {
        int mx = 0;
        for (char ch = l[i]; ch <= r[i]; ++ch) {
            auto& res = mp[ch];
            auto iter = ranges::upper_bound(res, id);
            if (iter == res.end()) {
                cout << "YES\n";
                return;
            } else {
                mx = max(mx, *iter);
            }
        }
        id = mx;
    }
    cout << "NO\n";
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