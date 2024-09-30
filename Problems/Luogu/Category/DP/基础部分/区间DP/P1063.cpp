#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    int m;
    cin >> m;
    vector<int> vec(m);
    for (int& v : vec) {
        cin >> v;
    }

    vec.insert(vec.end(), vec.begin(), vec.end());
    vec.pop_back();
    int n = vec.size();

    vector f(n, vector<int>(n));
    for (int len = 2; len <= n; ++len) {
        for (int l = 0, r = l + len - 1; r < n; ++l, ++r) {
            for (int k = l; k < r; ++k) {
                f[l][r] = max(f[l][r], f[l][k] + f[k + 1][r] + vec[l] * vec[k + 1] * vec[r + 1]);
            }
        }
    }

    int mx = 0;
    for (int i = 0; i < m; ++i) {
        mx = max(mx, f[i][i + m - 1]);
    }
    cout << mx << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}