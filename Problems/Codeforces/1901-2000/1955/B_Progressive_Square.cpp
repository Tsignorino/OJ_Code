#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, c, d;
    cin >> n >> c >> d;

    vector<int> a(n * n), b(n * n);
    for (int& v : a) {
        cin >> v;
    }
    sort(a.begin(), a.end());

    for (int i = 0; i < n * n; ++i) {
        b[i] = a[0] + i / n * c + i % n * d;
    }

    /*
        vector<vector<int>> res(n, vector<int>(n));
        for (int i = 1; i < n; ++i) {
            res[0][i] = res[0][i - 1] + d;
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                res[i][j] = res[i - 1][j] + c;
            }
        }
    */

    sort(b.begin(), b.end());
    cout << (a == b ? "YES" : "NO") << "\n";
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