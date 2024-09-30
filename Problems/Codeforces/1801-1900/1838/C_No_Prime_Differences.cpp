#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1000000007;

void solve() {
    int n, m;
    cin >> n >> m;

    vector vec(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            vec[i][j] = i * m + j + 1;
        }
    }

    int j = 0;

    vector res(vec);
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 1) {
            res[i] = vec[j++];
        }
    }
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            res[i] = vec[j++];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << res[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
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