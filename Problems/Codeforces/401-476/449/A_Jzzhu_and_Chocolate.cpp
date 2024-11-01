#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

/*
    考虑在一侧切的次数，枚举的长度最多有 sqrt(n) 种不同的取值

    长为 n 的边切出的长度为 len，那么切割次数最多为 n/len -1
*/

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    auto calc = [&](int x) -> ll {
        return (m / max(k - n / x + 2, 1)) * 1ll * x;
    };

    ll ans = 0;
    for (int len = 1; len <= n && len < 40000; ++len) {
        ans = max({ans, calc(len), calc(n / len)});
    }
    cout << (ans == 0 ? -1 : ans) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}