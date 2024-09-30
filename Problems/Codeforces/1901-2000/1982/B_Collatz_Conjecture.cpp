#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    int x, y, k;
    cin >> x >> y >> k;

    while (x >= y && k > 0) {
        int d = min(k, y - x % y);
        k -= d;
        x += d;
        while (x % y == 0) {
            x /= y;
        }
    }

    if (x < y) {
        // int d = min(k, y - x);
        // k -= d;
        // x += d;
        // if (x == y) {
        //     x = 1;
        // }
        // x += k % (y - 1);

        x = 1 + (x - 1 + k) % (y - 1);
    }

    cout << x << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}