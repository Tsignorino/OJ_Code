#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

static constexpr int dir[8][2] = {
    {1,  2 },
    {1,  -2},
    {2,  1 },
    {2,  -1},
    {-1, 2 },
    {-1, -2},
    {-2, 1 },
    {-2, -1},
};

void solve() {
    ll n;
    int m;
    cin >> n >> m;

    set<ll> s;
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        x--, y--;

        for (int k = 0; k < 8; ++k) {
            int nx = x + dir[k][0], ny = y + dir[k][1];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                s.emplace(nx * (n + 1) + ny);
            }
        }
        s.emplace(x * (n + 1) + y);
    }
    cout << n * n - s.size() << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}