#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;

    vector<pair<int, int>> vec(n);
    for (auto& v : vec) {
        cin >> v.first;
    }
    for (auto& v : vec) {
        cin >> v.second;
    }

    vector<int> sum(n + 1);
    vector<int> pre(n + 1);
    vector<int> suf(n + 1);

    ranges::sort(vec, [&](const auto& v1, const auto& v2) { return v1.second > v2.second; });
    for (int i = 0; i < n; ++i) {
        sum[i + 1] = sum[i] + vec[i].second;
    }
    for (int i = 0; i < n; ++i) { // 前 i 个最大值
        pre[i + 1] = max(pre[i], 2 * vec[i].first);
    }
    for (int i = n - 1; i >= 0; --i) { // 后 i 个最大值
        suf[i] = max(suf[i + 1], 2 * vec[i].first + vec[i].second);
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
