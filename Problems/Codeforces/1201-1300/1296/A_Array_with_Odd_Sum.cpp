#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;

    int odd = 0;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        odd += num & 1;
    }

    int even = n - odd;

    if (odd & 1 || even != 0 && odd) { // “奇数个奇数” 或者 “有偶数有奇数”
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