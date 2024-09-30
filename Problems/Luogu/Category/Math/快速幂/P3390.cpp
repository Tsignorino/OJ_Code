#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

// 矩阵快速幂（方阵）
template <typename T>
vector<vector<T>> multiply(vector<vector<T>>& a, vector<vector<T>>& b) { // 矩阵乘法
    int m = a.size(), n = b[0].size(), k = a[0].size();
    vector<vector<T>> res(m, vector<T>(n));
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
template <typename T>
vector<vector<T>> quickPow(vector<vector<T>> a, T b) {
    int n = a.size();
    vector<vector<T>> ans(n, vector<T>(n));
    for (int i = 0; i < n; ++i) {
        ans[i][i] = 1;
    }

    for (; b; b >>= 1) {
        if (b & 1) {
            ans = multiply(ans, a);
        }
        a = multiply(a, a);
    }
    return ans;
}

void solve() {
    int n;
    ll k;
    cin >> n >> k;
    vector a(n, vector<ll>(n));
    for (auto& row : a) {
        for (auto& v : row) {
            cin >> v;
        }
    }

    auto res = quickPow(a, k);
    for (auto& row : res) {
        for (auto& v : row) {
            cout << v << " ";
        }
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}