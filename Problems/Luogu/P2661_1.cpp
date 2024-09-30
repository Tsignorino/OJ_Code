#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;

    int mn = INT_MAX; // 记录最小环长度

    vector<int> pa(n + 1), d(n + 1);
    iota(pa.begin(), pa.end(), 0);

    function<int(int)> find = [&](int x) {
        if (pa[x] != x) {
            int tmp = pa[x];
            pa[x] = find(pa[x]);
            d[x] += d[tmp];
        }
        return pa[x];
    };

    auto upd = [&](int x, int y) {
        int rx = find(x), ry = find(y);
        if (rx != ry) {
            pa[rx] = ry;
            d[x] = d[y] + 1;
        } else {
            mn = min(mn, d[x] + d[y] + 1);
        }
    };

    for (int i = 1; i <= n; ++i) {
        int val;
        cin >> val;

        upd(i, val);
    }

    cout << mn << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}