#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define mod 1e9 + 7

void solve() {
    char g[11][11];
    int ans = 0;
    for (int i = 1; i < 11; ++i) {
        for (int j = 1; j < 11; ++j) {
            cin >> g[i][j];

            if (g[i][j] == 'X') {
                ans += min(min(i, 11 - i), min(j, 11 - j));
            }
        }
    }
    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int count;
    cin >> count;
    while (count--) {
        solve();
    }

    return 0;
}
