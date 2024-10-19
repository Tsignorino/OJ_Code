#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

/*
    https://ac.nowcoder.com/acm/contest/88455/B
*/

void solve() {
    ll n;
    cin >> n;

    ll cnt = 0;
    while (n != 0) {
        n = n / 2 - (n % 2 == 0);
        cnt++;
    }
    cout << cnt << "\n";
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