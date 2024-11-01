#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    int x, y;
    cin >> x >> y;

    if (x < y) {
        cout << -1 << "\n";
        return;
    }

    auto func = [&](int v) -> double {
        if (v >= y * 2) { // 每一组的长度不能小于 2y
            int k = v / (y * 2);
            return double(v) / (k * 2);
        }
        return 1e9;
    };

    cout << fixed << setprecision(12) << min(func(x + y), func(x - y)) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}