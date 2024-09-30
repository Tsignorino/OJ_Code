#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

vector<vector<long long>> multiply(vector<vector<long long>> a, vector<vector<long long>> b, int mod) { // 矩阵乘法
    int m = a.size(), n = b[0].size(), k = a[0].size();
    vector res(m, vector<long long>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int c = 0; c < k; ++c) {
                res[i][j] += a[i][c] * b[c][j];
                res[i][j] %= mod;
            }
        }
    }
    return res;
}
vector<vector<long long>> quickPow(vector<vector<long long>> a, long long b, int mod) {
    int n = a.size();
    vector ans(n, vector<long long>(n));
    for (int i = 0; i < n; ++i) {
        ans[i][i] = 1;
    }

    for (; b; b >>= 1) {
        if (b & 1) {
            ans = multiply(ans, a, mod);
        }
        a = multiply(a, a, mod);
    }
    return ans;
}

vector<int> nextArray(string& s) {
    int n = s.size();
    vector<int> nxt(n + 1);
    nxt[0] = -1;
    for (int i = 2, j = 0; i <= n; ++i) {
        while (j != -1 && s[i - 1] != s[j]) {
            j = nxt[j];
        }
        nxt[i] = ++j;
    }
    return nxt;
}

void solve() {
    int n, m, mod;
    cin >> n >> m >> mod;
    string s;
    cin >> s;

    auto nxt(nextArray(s));
    s.insert(s.begin(), ' ');

    // f[i][j] 表示 第 i 个数，匹配到 X 中第 j 个字符
    // g[k][j] 表示 匹配了一个长度为 k 的串，有多少种加数字的方法使得匹配长度变为 j
    vector vec(m + 1, vector<long long>(m + 1));
    for (int i = 0; i < m; ++i) {
        for (char ch = '0'; ch <= '9'; ++ch) {
            int j = i;
            while (j && s[j + 1] != ch) {
                j = nxt[j];
            }
            if (s[j + 1] == ch) {
                j++;
            }
            vec[i][j]++;
        }
    }

    auto res = quickPow(vec, n, mod);
    long long ans = 0;
    for (int i = 0; i < m; ++i) {
        ans += res[0][i];
        ans %= mod;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
