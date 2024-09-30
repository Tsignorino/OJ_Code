#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;

    int a[n], b[n];
    vector<int> preSum(n + 1), preMax(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        preSum[i + 1] = preSum[i] + a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        preMax[i + 1] = max(preMax[i], b[i]);
    }

    // 首次完成当前请求，获得 a[i]，后续获得 b[i]
    int ans = 0;
    for (int i = min(k, n); i >= 0; --i) {
        ans = max(ans, preSum[i] + preMax[i] * (k - i));
    }
    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int count;
    cin >> count;
    while (count--) {
        solve();
    }

    return 0;
}
