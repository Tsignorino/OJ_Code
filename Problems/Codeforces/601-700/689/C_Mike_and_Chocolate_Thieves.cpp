#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    ll m;
    cin >> m;

    // 求一个数 x，使得最大值不超过 x 的公比为整数的等比数列的数量恰好为 m.
    auto check = [&](ll x) {
        ll ans = 0;
        for (int k = 2; x / k / k / k > 0; ++k) {
            ans += x / k / k / k;
        }
        return ans;
    };

    ll l = 0, r = m * 8 + 1;
    while (l + 1 < r) {
        ll mid = l + (r - l) / 2;

        (check(mid) >= m ? r : l) = mid;
    }
    cout << (check(r) == m ? r : -1) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}