// Date: 2024-12-05  星期四

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
static constexpr int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};

void solve() {
    const int N = 3;
    vector<string> g(N);
    for (string& s : g) {
        cin >> s;
    }

    string ans = "ZZZ";
    string tmp;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            tmp.push_back(g[i][j]);
            for (int k = 0; k < 8; ++k) {
                int x = i + dx[k], y = j + dy[k];
                if (x >= 0 && x < N && y >= 0 && y < N) {
                    tmp.push_back(g[x][y]);
                    for (int nk = 0; nk < 8; ++nk) {
                        int nx = x + dx[nk], ny = y + dy[nk];
                        if (nx >= 0 && nx < N && ny >= 0 && ny < N && !(nx == i && ny == j)) {
                            tmp.push_back(g[nx][ny]);
                            ans = min(ans, tmp);
                            // cerr << i << " " << j << " " << x << " " << y << " " << nx << " " << ny << "\n";
                            // cerr << tmp << "\n";
                            tmp.pop_back();
                        }
                    }
                    tmp.pop_back();
                }
            }
            tmp.pop_back();
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}