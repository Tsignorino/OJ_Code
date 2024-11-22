#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, k;
    cin >> n >> k;

    if (n == 1) {
        cout << k << "\n";
    } else {
        vector<int> ans(n);
        ans[0] = (1 << (__lg(k + 1))) - 1;
        ans[1] = k - ans[0];
        for (int& v : ans) {
            cout << v << " ";
        }
        cout << "\n";
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