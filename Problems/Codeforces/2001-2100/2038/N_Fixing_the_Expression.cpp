// Date: 2024-11-27  星期三

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int a, b;
    char op;
    cin >> a >> op >> b;

    if (a < b) {
        op = '<';
    } else if (a > b) {
        op = '>';
    } else {
        op = '=';
    }

    cout << a << op << b << "\n";
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