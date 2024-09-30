#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

static constexpr int dir[4][2] = {
    {-1, 0 },
    {0,  1 },
    {1,  0 },
    {0,  -1}
};

void solve() {
    int h, w, n;
    cin >> h >> w >> n;

    vector<string> g(h, string(w, '.'));

    int x = 0, y = 0, k = 0;
    while (n--) {
        if (g[x][y] == '.') {
            k = (k + 1) % 4;
            g[x][y] = '#';
        } else {
            k = (k - 1 + 4) % 4;
            g[x][y] = '.';
        }
        x = (x + dir[k][0] + h) % h, y = (y + dir[k][1] + w) % w;
    }

    for (int i = 0; i < h; ++i) {
        cout << g[i] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}