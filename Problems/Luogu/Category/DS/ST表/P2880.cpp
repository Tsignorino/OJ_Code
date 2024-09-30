#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    int len = __lg(n);
    vector<vector<array<int, 2>>> st(n, vector<array<int, 2>>(len + 1));
    auto init = [&]() -> int {
        for (int i = 0; i < n; ++i) {
            st[i][0] = {vec[i], vec[i]};
        }
        for (int i = 1; i <= len; ++i) {
            for (int j = 0; j + (1 << i) - 1 < n; ++j) {
                auto& [maxV, minV] = st[j][i];
                maxV = max(st[j][i - 1][0], st[j + (1 << (i - 1))][i - 1][0]);
                minV = min(st[j][i - 1][1], st[j + (1 << (i - 1))][i - 1][1]);
            }
        }
        return 0;
    }();

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;

        int len = __lg(r - l + 1);
        array<int, 2>& ll = st[l][len];
        array<int, 2>& rr = st[r - (1 << len) + 1][len];
        cout << max(ll[0], rr[0]) - min(ll[1], rr[1]) << "\n";
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(20);

    solve();

    return 0;
}
