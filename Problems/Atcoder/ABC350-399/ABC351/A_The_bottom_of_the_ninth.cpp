#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int ans = 1;
    for (int i = 0; i < 9; ++i) {
        int v;
        cin >> v;
        ans += v;
    }
    for (int i = 0; i < 8; ++i) {
        int v;
        cin >> v;
        ans -= v;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}