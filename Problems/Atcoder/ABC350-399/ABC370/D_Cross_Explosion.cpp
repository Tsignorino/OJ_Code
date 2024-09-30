#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<set<int>> row(n), col(m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            row[i].emplace(j);
            col[j].emplace(i);
        }
    }

    int ans = n * m;
    while (q--) {
        int x, y;
        cin >> x >> y;
        x--, y--;

        if (row[x].contains(y)) {
            row[x].extract(y);
            col[y].extract(x);
            ans--;
        } else {
            auto iter = row[x].lower_bound(y);
            if (iter != row[x].begin()) {
                int c = *prev(iter);
                row[x].extract(c);
                col[c].extract(x);
                ans--;
            }
            if (iter != row[x].end()) {
                int c = *iter;
                row[x].extract(c);
                col[c].extract(x);
                ans--;
            }

            iter = col[y].lower_bound(x);
            if (iter != col[y].begin()) {
                int r = *prev(iter);
                col[y].extract(r);
                row[r].extract(y);
                ans--;
            }
            if (iter != col[y].end()) {
                int r = *iter;
                col[y].extract(r);
                row[r].extract(y);
                ans--;
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}