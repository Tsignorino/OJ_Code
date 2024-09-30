#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

/*
    https://ac.nowcoder.com/acm/contest/89510/D

    考虑把幂次转成进制问题
*/

void solve() {
    ll n, k;
    cin >> n >> k;

    ll ans = 1;
    if (k > 1) {
        while (n) {
            ans = max(ans, n % k);
            n /= k;
        }
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