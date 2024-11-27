// Date: 2024-11-27  星期三

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    ll n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<ll> preSum(n + 1);
    vector<int> nxt(n + 1);
    for (int i = 0; i < n; ++i) {
        preSum[i + 1] = preSum[i] + a[i];
        nxt[i + 1] = nxt[i] + (a[i] > 0);
    }

    if (preSum[n] % 3) {
        cout << 0 << "\n";
        return;
    }

    vector<int> f(n + 2);
    vector<int> nxt2(n + 2);
    nxt2[n + 1] = n + 1;
    for (int i = n; i > 0; i--) {
        f[i] = f[i + 1];
        if (nxt[n] - nxt[i - 1] && preSum[n] - preSum[i - 1] == preSum[n] / 3) {
            f[i]++;
        }

        nxt2[i] = nxt2[i + 1];
        if (a[i - 1] > 0) {
            nxt2[i] = i;
        }
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        if (nxt[i] && preSum[i] == preSum[n] / 3) {
            if (int r = nxt2[i + 1]; r < n) {
                ans += f[r + 1];
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}