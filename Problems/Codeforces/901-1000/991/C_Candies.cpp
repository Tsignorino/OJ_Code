#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

void solve() {
    ll n;
    cin >> n;

    auto check = [&](ll k) -> bool {
        ll tot = 0, m = n;
        while (m > k) {
            tot += k;
            m -= k;
            m -= m / 10;
        }

        return (tot + m) * 2 >= n;
    };

    ll l = 0, r = n + 1;
    while (l + 1 < r) {
        ll mid = l + (r - l) / 2;
        (check(mid) ? r : l) = mid;
    }
    cout << r << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(20);

    solve();

    return 0;
}
