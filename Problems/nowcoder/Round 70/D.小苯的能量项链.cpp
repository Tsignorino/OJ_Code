// Date: 2024-12-01  星期天

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

// 首次AC代码：https://ac.nowcoder.com/acm/contest/view-submission?submissionId=73855557

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int& v : a) {
        cin >> v;
    }

    if (n == 1) {
        cout << a[0] << "\n";
        return;
    }

    vector<int> suf(n + 2);
    for (int i = n - 1; i >= 0; --i) {
        suf[i] = max(suf[i + 1], a[i]);
    }

    int ans = 0;
    for (int i = 0; i <= min(n, k); ++i) {
        ans = max(ans, a[i] + suf[max(i + 1, n - k - 1 + i)]);
    }
    cout << ans << "\n";
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