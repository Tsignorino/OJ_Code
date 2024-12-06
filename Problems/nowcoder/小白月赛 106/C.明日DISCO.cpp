// Date: 2024-12-06  星期五

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int dx[] = {1, 0, -1, 0};
static constexpr int dy[] = {0, 1, 0, -1};

// 首次 AC 代码：https://ac.nowcoder.com/acm/contest/view-submission?submissionId=73964343

void solve() {
    int n;
    cin >> n;

    vector g(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> g[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (g[i][j] == 0) {
                continue;
            }
            for (int k = 0; k < 4; ++k) {
                int x = i + dx[k], y = j + dy[k];
                if (x >= 0 && x < n && y >= 0 && y < n && g[i][j] * 1ll * g[x][y] > 0) {
                    cout << "NO\n";
                    return;
                }
            }
        }
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}