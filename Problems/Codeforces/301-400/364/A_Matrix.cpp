// Date: 2024-11-29  星期五

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

// 相当于挑选两个子数组，使其和的乘积等于 a
void solve() {
    int a;
    cin >> a;

    string s;
    cin >> s;

    int n = s.size();
    vector<int> cnt(9 * n + 1, 0);
    for (int i = 0; i < n; ++i) {
        int sum = 0;
        for (int j = i; j < n; ++j) {
            sum += s[j] - '0';
            cnt[sum]++;
        }
    }

    ll ans = 0;
    if (a == 0) {
        int v = n * (n + 1) / 2;
        ans = v * 1ll * v - (v - cnt[0]) * 1ll * (v - cnt[0]);
    } else {
        for (int i = 1; i <= 9 * n; ++i) {
            if (a % i == 0 && a / i <= 9 * n) {
                ans += cnt[i] * 1ll * cnt[a / i];
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}