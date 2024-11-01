#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    vector<int> cnt(n + 1); // 统计 1 的个数
    vector<ll> preSum(n + 1);
    for (int i = 0; i < n; ++i) {
        cnt[i + 1] = cnt[i] + (vec[i] == 1);
        preSum[i + 1] = preSum[i] + vec[i];
    }

    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;

        // 可能的最小子数组之和 minV = (cnt[r] - cnt[l - 1]) * 1ll + (r - l + 1)
        cout << (l == r || (cnt[r] - cnt[l - 1]) * 1ll + (r - l + 1) > preSum[r] - preSum[l - 1] ? "NO" : "YES") << "\n";
    }
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
