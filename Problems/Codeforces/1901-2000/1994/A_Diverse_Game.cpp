#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    vector vec(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> vec[i][j];
        }
    }

    if (n == 1 && m == 1) {
        cout << -1 << "\n";
        return;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << vec[i][j] % (n * m) + 1 << " ";
        }
        cout << "\n";
    }

    // mySolve:
    // if (n > 1) {
    //     for (int i = 0; i < n; ++i) {
    //         for (int j = 0; j < m; ++j) {
    //             cout << vec[(i + 1) % n][j] << " ";
    //         }
    //         cout << "\n";
    //     }
    // } else {
    //     for (int j = 0; j < m; ++j) {
    //         cout << vec[0][(j + 1) % m] << " ";
    //     }
    //     cout << "\n";
    // }
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