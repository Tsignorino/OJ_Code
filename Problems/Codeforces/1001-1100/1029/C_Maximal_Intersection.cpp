#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> vec(n);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i].first >> vec[i].second;
    }

    auto merge = [&](pair<int, int>& p, pair<int, int>& q) {
        return make_pair(max(p.first, q.first), min(p.second, q.second));
    };

    vector<pair<int, int>> suf(n + 1);
    suf[n].second = 1e9;
    for (int i = n - 1; i > 0; --i) {
        suf[i] = merge(suf[i + 1], vec[i]);
    }

    pair<int, int> pre({0, 1e9});
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        auto& p = vec[i];
        auto m = merge(pre, suf[i + 1]);
        ans = max(ans, m.second - m.first);
        pre = merge(pre, p);
    }

    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(20);

    solve();

    return 0;
}
