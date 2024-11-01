#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

/*
    k k+1 k+2 ... k+n-1
    [k, k+i] and [k+i+1, k+n-1]
*/

void solve() {
    ll n, k;
    cin >> n >> k;

    auto calc = [&](ll x) { // [0, x]
        return (x + 1) * k + x * (x + 1) / 2;
    };

    ll sum = calc(n - 1);

    ll l = 0, r = n;
    while (l + 1 < r) {
        ll m = l + (r - l) / 2;

        if (calc(m) * 2 <= sum) {
            l = m;
        } else {
            r = m;
        }
    }

    cout << min(abs(calc(l) * 2 - sum), abs(calc(r) * 2 - sum)) << "\n";
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