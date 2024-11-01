#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    ll n, m, k;
    cin >> n >> m >> k;

    ll v = lcm(n, m);
    cout << *ranges::partition_point(views::iota(0ll, LLONG_MAX), [&](ll x) { return x / n + x / m - x / v * 2 < k; });
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}