#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    ll sx, sy, ex, ey;
    cin >> sx >> sy >> ex >> ey;

    if ((sx + sy) % 2) {
        sx--;
    }
    if ((ex + ey) % 2) {
        ex--;
    }

    cout << max({abs(sy - ey), abs(sx - ex + sy - ey) / 2, abs(sx - ex - sy + ey) / 2}) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}