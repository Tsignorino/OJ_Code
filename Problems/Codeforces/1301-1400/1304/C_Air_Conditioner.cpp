#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int mod = 1e9 + 7;

void solve() {
    int n, s;
    cin >> n >> s;

    bool flag = true;
    for (int i = 0, ll = s, rr = s, pre = 0; i < n; ++i) {
        int t, l, r;
        cin >> t >> l >> r;

        if (flag == false) {
            continue;
        }

        ll -= t - pre;
        rr += t - pre;
        pre = t;
        if (r < ll || l > rr) {
            flag = false;
        }

        ll = max(ll, l);
        rr = min(rr, r);
    }
    cout << (flag ? "YES" : "NO") << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
