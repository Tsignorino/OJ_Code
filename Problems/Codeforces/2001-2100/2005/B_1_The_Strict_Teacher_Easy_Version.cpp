#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;

    int a, b;
    cin >> a >> b;
    if (a > b) {
        swap(a, b);
    }

    int d;
    cin >> d;

    if (d < a) {
        cout << a - 1 << "\n";
    } else if (d > b) {
        cout << n - b << "\n";
    } else {
        cout << (b - a) / 2 << "\n";
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