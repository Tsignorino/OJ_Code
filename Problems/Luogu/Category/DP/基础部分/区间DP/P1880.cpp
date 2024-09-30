#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    // 拆环
    vec.insert(vec.end(), vec.begin(), vec.end());
    vec.pop_back();

    int m = vec.size();
    vector<int> pre(m + 1);
    vector f1(m, vector<int>(m)); // max
    vector f2(m, vector<int>(m, INT_MAX)); // min
    for (int i = 0; i < m; ++i) {
        pre[i + 1] = pre[i] + vec[i];
        f1[i][i] = f2[i][i] = 0;
    }

    for (int len = 2; len <= m; ++len) {
        for (int l = 0, r = l + len - 1; r < m; ++l, ++r) {
            for (int k = l; k < r; ++k) {
                f1[l][r] = max(f1[l][r], f1[l][k] + f1[k + 1][r] + pre[r + 1] - pre[l]);
                f2[l][r] = min(f2[l][r], f2[l][k] + f2[k + 1][r] + pre[r + 1] - pre[l]);
            }
        }
    }

    int mx = 0, mn = INT_MAX;
    for (int i = 0; i < n; ++i) {
        mx = max(mx, f1[i][i + n - 1]);
        mn = min(mn, f2[i][i + n - 1]);
    }
    cout << mn << "\n" << mx << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}