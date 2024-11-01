#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

/*
    寻找每个序列第二小的 mex，取最大值为 k，讨论 k 和 m 的大小即可
*/

void solve() {
    int n, m;
    cin >> n >> m;

    int k = 0;
    for (int i = 0; i < n; ++i) {
        int q;
        cin >> q;

        vector<int> vec(q + 2);
        for (int i = 0; i < q; ++i) {
            int v;
            cin >> v;
            if (v <= q + 1) {
                vec[v] = 1;
            }
        }

        int mex = 0;
        while (vec[mex]) {
            mex++;
        }
        mex++;
        while (vec[mex]) {
            mex++;
        }

        k = max(k, mex);
    }

    if (k >= m) {
        cout << (m + 1ll) * k << "\n";
    } else {
        cout << (k + 1ll) * k + (k + 1ll + m) * (m - k) / 2 << "\n";
    }
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