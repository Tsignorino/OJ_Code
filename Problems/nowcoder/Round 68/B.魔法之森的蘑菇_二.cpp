// Date: 2024-12-11  星期三

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<string> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] = '%' + a[i];
    }

    vector s(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + (a[i][j] == '.');
        }
    }

    auto get = [&](int a, int b, int c, int d) {
        return s[c][d] - s[c][b - 1] - s[a - 1][d] + s[a - 1][b - 1];
    };

    int x1, y1, x2, y2, S = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int x = i; x <= n; x++) {
                for (int y = j; y <= m; y++) {
                    if (get(i, j, x, y) == (x - i + 1) * (y - j + 1)) {
                        if ((x - i + 1) * (y - j + 1) > S) {
                            S = (x - i + 1) * (y - j + 1);
                            x1 = i, y1 = j;
                            x2 = x, y2 = y;
                        }
                    }
                }
            }
        }
    }
    cout << x1 << " " << y1 << " " << x2 << " " << y2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}