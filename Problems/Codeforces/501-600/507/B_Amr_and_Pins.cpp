// Date: 2024-11-29  星期五

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int r, x, y, nx, ny;
    cin >> r >> x >> y >> nx >> ny;

    double dis = hypot(x - nx, y - ny);
    cout << ceil(dis / (r * 2)) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}