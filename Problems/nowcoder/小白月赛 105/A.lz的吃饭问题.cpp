// Date: 2024-11-22  星期五

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int a, b;
    cin >> a >> b;

    int c, d;
    cin >> c >> d;

    if (a * b < c * d) {
        cout << "lz\n";
    } else {
        cout << "gzy\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}