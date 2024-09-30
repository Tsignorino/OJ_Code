#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    ll n;
    cin >> n;

    int cnt = 1;
    while (cnt * 1ll * (cnt + 1) / 2 < n) {
        cnt++;
    }
    cnt--;

    cout << (n - cnt * 1ll * (cnt + 1) / 2) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}