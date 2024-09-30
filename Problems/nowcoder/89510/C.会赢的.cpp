#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

/*
    https://ac.nowcoder.com/acm/contest/89510/C
*/

void solve() {
    int x, y;
    cin >> x >> y;

    if (x < 0 || y < 0 || abs(x - y) > 1) {
        cout << "PING\n";
        return;
    } else if ((x + y) & 1) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
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