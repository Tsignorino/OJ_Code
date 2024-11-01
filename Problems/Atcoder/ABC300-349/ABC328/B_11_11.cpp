#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int v;
        cin >> v;

        int res = i;
        if (res >= 10 && res / 10 != res % 10) {
            continue;
        }
        if (res >= 10) {
            res /= 10;
        }
        ans += res <= v;
        ans += (res * 10 + res) <= v;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}