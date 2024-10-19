#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

/*
    https://ac.nowcoder.com/acm/contest/88392/A
*/

void solve() {
    int x, y, n;
    cin >> x >> y >> n;

    cout << (x + y <= n ? "YES" : "NO") << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}