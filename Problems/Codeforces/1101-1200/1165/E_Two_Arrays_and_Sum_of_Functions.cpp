#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 998244353;

void solve() {
    int n;
    cin >> n;

    // 贡献法
    // a[i] 左侧有 (i+1) 个子数组左端点，右侧有 (n-i) 个子数组右端点
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] *= (i + 1) * 1ll * (n - i);
    }
    for (ll& v : b) {
        cin >> v;
    }

    // 排序不等式
    ranges::sort(a, greater<ll>());
    ranges::sort(b);

    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        sum = (sum + a[i] % MOD * b[i]) % MOD;
    }
    cout << sum << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);

    solve();

    return 0;
}
