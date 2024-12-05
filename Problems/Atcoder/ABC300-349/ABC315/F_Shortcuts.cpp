// Date: 2024-12-05  星期四

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }

    const int S = 31;
    vector f(n, vector<double>(S, numeric_limits<double>::max()));
    f[0][0] = 0;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < S; ++j) {
            for (int k = i + 1; k < n && j + k - i - 1 < S; ++k) {
                int nj = j + k - i - 1;
                f[k][nj] = min(f[k][nj], f[i][j] + hypot(x[i] - x[k], y[i] - y[k]));
            }
        }
    }

    double ans = numeric_limits<double>::max();
    for (int i = 0; i < S; ++i) {
        ans = min(ans, f[n - 1][i] + (i == 0 ? 0 : pow(2, i - 1)));
    }
    cout << fixed << setprecision(20) << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}