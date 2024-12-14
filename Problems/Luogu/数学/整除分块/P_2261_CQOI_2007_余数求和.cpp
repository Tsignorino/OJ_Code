#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;

    // 整除分块：k % i = k - k / i * i
    ll ans = n * 1ll * k;
    for (int l = 1, r = 0; l <= n; l = r + 1) {
        if (k / l == 0) {
            break;
        }
        r = min(n, k / (k / l));
        ans -= (k / l) * 1ll * (r - l + 1) * (l + r) / 2;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}