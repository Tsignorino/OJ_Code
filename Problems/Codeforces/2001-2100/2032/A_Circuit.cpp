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

    int cnt = 0;
    for (int i = 0; i < n * 2; ++i) {
        int v;
        cin >> v;
        cnt += v == 1;
    }
    cout << cnt % 2 << " " << min(cnt, 2 * n - cnt) << "\n"; //(cnt > n ? 2 * n - cnt : cnt)
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