#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

void solve() {
    int a, b, n, m;
    cin >> a >> b >> n >> m;
    vector<pair<int, int>> x, y;
    for (int i = 0; i < n; ++i) {
        int fi, se;
        cin >> fi >> se;
        x.emplace_back(fi, se);
        y.emplace_back(se, fi);
    }

    set<pair<int, int>> set; // 记录已删除的元素

    ranges::sort(x);
    ranges::sort(y);

    int u = 1, d = a, l = 1, r = b;
    int hl = 0, hr = n - 1, vl = 0, vr = n - 1;

    vector<int> ans(2);
    for (int i = 0; i < m; ++i) {
        char ch;
        int k;
        cin >> ch >> k;

        if (ch == 'U') {
            u += k;
            while (vl <= vr && x[vl].first < u) {
                if (!set.contains(x[vl])) {
                    ans[i % 2]++;
                    set.insert(x[vl]);
                }
                vl++;
            }
        }
        if (ch == 'D') {
            d -= k;
            while (vl <= vr && x[vr].first > d) {
                if (!set.contains(x[vr])) {
                    ans[i % 2]++;
                    set.insert(x[vr]);
                }
                vr--;
            }
        }
        if (ch == 'L') {
            l += k;
            while (hl <= hr && y[hl].first < l) {
                if (!set.contains(make_pair(y[hl].second, y[hl].first))) {
                    ans[i % 2]++;
                    set.insert(make_pair(y[hl].second, y[hl].first));
                }
                hl++;
            }
        }
        if (ch == 'R') {
            r -= k;
            while (hl <= hr && y[hr].first > r) {
                if (!set.contains(make_pair(y[hr].second, y[hr].first))) {
                    ans[i % 2]++;
                    set.insert(make_pair(y[hr].second, y[hr].first));
                }
                hr--;
            }
        }
    }

    cout << ans[0] << " " << ans[1] << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
