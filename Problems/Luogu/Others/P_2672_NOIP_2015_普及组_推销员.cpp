#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;

    vector<int> s(n), a(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    ranges::sort(idx, [&](int i, int j) { return a[i] > a[j]; });

    vector<int> sum(n + 1);
    for (int i = 0; i < n; ++i) {
        sum[i + 1] = sum[i] + a[idx[i]];
    }

    vector<int> pre(n + 1);
    for (int i = 0; i < n; ++i) { // 前 i 个最大值
        pre[i + 1] = max(pre[i], 2 * s[idx[i]]);
    }
    vector<int> suf(n + 1);
    for (int i = n - 1; i >= 0; --i) { // 后 i 个最大值
        suf[i] = max(suf[i + 1], 2 * s[idx[i]] + a[idx[i]]);
    }

    for (int i = 1; i <= n; i++) {
        // 舍掉推销疲劳值最小的，再走一段路
        cout << max(sum[i] + pre[i], sum[i - 1] + suf[i - 1]) << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
