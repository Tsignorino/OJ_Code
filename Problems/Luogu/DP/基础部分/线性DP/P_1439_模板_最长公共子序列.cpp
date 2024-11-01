#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;

    // vector<int> a(n), b(n);
    // for (int i = 0; i < n; ++i) {
    //     cin >> a[i];
    // }
    // for (int i = 0; i < n; ++i) {
    //     cin >> b[i];
    // }
    //
    // vector f(n + 1, vector<int>(n + 1));
    // for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j < n; ++j) {
    //         f[i + 1][j + 1] = max(f[i][j + 1], f[i + 1][j]);
    //         if (a[i] == b[j]) {
    //             f[i + 1][j + 1] = max(f[i + 1][j + 1], f[i][j] + 1);
    //         }
    //     }
    // }
    // cout << f[n][n] << "\n";

    vector<int> a(n);
    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        mp[a[i]] = i;
    }

    vector<int> b(n);
    for (int& v : b) {
        cin >> v;
        v = mp[v];
    }

    vector<int> f;
    for (int& v : b) {
        auto iter = ranges::upper_bound(f, v);
        if (iter == f.end()) {
            f.emplace_back(v);
        } else {
            *iter = v;
        }
    }
    cout << f.size() << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}