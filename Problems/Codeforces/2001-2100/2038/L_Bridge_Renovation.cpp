// Date: 2024-11-27  星期三

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

/*

25 + 25
21 + 21 + 18
18 + 18 + 18

25 + 21
25 + 18
21 + 18 + 18

*/

void solve() {
    int n;
    cin >> n;

    // cout << n * 2 / 3 + (n * 2 % 3 + n + 1) / 2 << "\n";
    cout << n + (n + 5) / 6 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}