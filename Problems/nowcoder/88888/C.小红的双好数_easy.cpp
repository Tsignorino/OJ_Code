#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

/*
    https://ac.nowcoder.com/acm/contest/88888/C
*/

void solve() {
    ll n;
    cin >> n;

    if (n == 2) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    cout << 2 << " " << (n == 1 ? 3 : n) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}