// Date: 2024-12-20  星期五

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

// 矩阵快速幂（方阵）
vector<vector<ll>> multiply(vector<vector<ll>>& a, vector<vector<ll>>& b) { // 矩阵乘法
    int m = a.size(), n = b[0].size(), k = a[0].size();
    vector<vector<ll>> res(m, vector<ll>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int c = 0; c < k; ++c) {
                res[i][j] += a[i][c] * b[c][j];
                res[i][j] %= MOD;
            }
        }
    }
    return res;
}
// a^n @ f，其中 @ 是矩阵乘法，f 为列向量
vector<vector<ll>> qpow_mul(vector<vector<ll>> a, ll b, vector<vector<ll>> f = {}) {
    int n = a.size();
    if (f.empty()) {
        f = vector(n, vector<ll>(n));
        for (int i = 0; i < n; ++i) {
            f[i][i] = 1;
        }
    }
    for (; b; b >>= 1) {
        if (b & 1) {
            f = multiply(a, f);
        }
        a = multiply(a, a);
    }
    return f;
}

void solve() {
    int n;
    cin >> n;

    if (n <= 3) {
        cout << 1 << "\n";
        return;
    }

    vector<vector<ll>> f {{1}, {1}, {1}};
    vector<vector<ll>> mul {
        {0, 1, 0},
        {0, 0, 1},
        {1, 0, 1}
    };
    cout << qpow_mul(mul, n - 3, f).back()[0] << "\n";
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