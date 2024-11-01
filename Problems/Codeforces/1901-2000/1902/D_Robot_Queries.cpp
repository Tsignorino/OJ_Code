#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, q;
    string s;
    cin >> n >> q >> s;

    using PII = pair<int, int>;
    map<char, PII> dir {
        {'U', {0, 1} },
        {'D', {0, -1}},
        {'L', {-1, 0}},
        {'R', {1, 0} }
    };

    vector<PII> pre(n + 1);
    PII o {};
    map<PII, vector<int>> mp {
        {o, vector {0}}
    };
    for (int i = 0; i < n; ++i) {
        o.first += dir[s[i]].first, o.second += dir[s[i]].second;
        pre[i + 1] = o;
        mp[o].emplace_back(i + 1);
    }

    while (q--) {
        int x, y, l, r;
        cin >> x >> y >> l >> r;

        auto& vec = mp[pair(x, y)];
        if (!vec.empty() && (vec.front() < l || vec.back() >= r)) {
            cout << "YES\n";
            continue;
        }

        PII p = {pre[r].first + pre[l - 1].first - x, pre[r].second + pre[l - 1].second - y};
        auto iter = ranges::lower_bound(mp[p], l - 1);
        if (iter != mp[p].end() && *iter <= r) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}