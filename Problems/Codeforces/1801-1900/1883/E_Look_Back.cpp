#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;

    int pre;
    cin >> pre;

    unsigned long long ans = 0;
    for (int i = 1, v = 0, cnt = 0, tmp; i < n; ++i) {
        cin >> v;
        if (v <= pre) {
            tmp = (pre - 1) / v;
            cnt += tmp ? 32 - __builtin_clz(tmp) : 0;
        } else {
            tmp = v / pre;
            cnt = tmp ? max(cnt - 31 + __builtin_clz((tmp)), 0) : 0;
        }
        ans += cnt;
        pre = v;
    }
    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(20);

    int count;
    cin >> count;
    while (count--) {
        solve();
    }

    return 0;
}
