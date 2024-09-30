#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> cnt(n + 1);
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        if (val < n) {
            cnt[val]++;
        }
    }

    int mex = 0;
    while (cnt[mex] > 0) {
        mex++;
    }

    // 枚举选哪个，用 f[i] 表示去掉所有 i 的后续操作的代价之和
    int ans = mex * (cnt[0] - 1);
    vector<int> f(mex);
    for (int i = 1; i < mex; ++i) {
        f[i] = INT_MAX;
        for (int j = 0; j < i; ++j) {
            f[i] = min(f[i], f[j] + cnt[j] * i);
        }
        ans = min(ans, f[i] + mex * (cnt[i] - 1));
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
