#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    ll a, b;
    cin >> a >> b;

    cout << (a * (a + 1) / 2 % MOD * b + a) % MOD * (b * (b - 1) / 2 % MOD) % MOD << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}