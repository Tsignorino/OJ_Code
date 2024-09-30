#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/*
    数字三角形
*/
void solve() {
    int n;
    cin >> n;

    vector<vector<int>> vec(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            cin >> vec[i][j];
        }
    }

    // vector<vector<int>> f(n + 1, vector<int>(n + 1));
    // f[1][1] = vec[1][1];
    // for (int i = 2; i <= n; ++i) {
    //     for (int j = 1; j <= i; ++j) {
    //         f[i][j] = max(f[i - 1][j], f[i - 1][j - 1]) + vec[i][j];
    //     }
    // }

    // int mx = 0;
    // for (int i = 1; i <= n; ++i) {
    //     mx = max(mx, f[n][i]);
    // }
    // cout << mx << "\n";

    vector<int> f(n + 1);
    f[1] = vec[1][1];
    for (int i = 2; i <= n; ++i) {
        for (int j = i; j > 0; --j) {
            f[j] = max(f[j - 1], f[j]) + vec[i][j];
        }
    }
    cout << ranges::max(f) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}