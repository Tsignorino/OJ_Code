#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> vec(k);
    for (int& v : vec) {
        cin >> v;
    }

    if (k % 2 == 0) {
        int ans = 0;
        for (int i = 1; i < k; i += 2) {
            ans += vec[i] - vec[i - 1];
        }
        cout << ans << "\n";
    } else {
        vector<int> pre(k + 1);
        for (int i = 1; i < k; i += 2) {
            pre[i + 1] = pre[i] + pre[i - 1] + vec[i] - vec[i - 1];
        }

        vector<int> suf(k + 1);
        for (int i = k - 2; i >= 0; i -= 2) {
            suf[i - 1] = suf[i] + suf[i + 1] + vec[i + 1] - vec[i];
        }

        int ans = n;
        for (int i = 0; i < k; i += 2) { // 去除的一定是偶数索引
            ans = min(ans, pre[i] + suf[i]);
        }
        cout << ans << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}