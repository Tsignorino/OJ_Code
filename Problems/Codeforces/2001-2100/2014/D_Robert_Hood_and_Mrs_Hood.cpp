#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

// #include "_debug.h"

void solve() {
    int n, d, k;
    cin >> n >> d >> k;

    vector<int> l(n + 1), r(n + 1);
    for (int i = 0; i < k; ++i) {
        int a, b;
        cin >> a >> b;
        a--, b--;

        l[a]++, r[b]++;
    }

    vector<ll> pre(n + 1);
    for (int i = 0; i < n; ++i) {
        pre[i + 1] = pre[i] + r[i];
    }

    vector<ll> suf(n + 1);
    for (int i = n - 1; i >= 0; --i) {
        suf[i] = suf[i + 1] + l[i];
    }

    // debug(pre);
    // debug(suf);

    int mn = n + 1, mx = -1;
    int p = 1, q = 1;
    for (int i = 0; i <= n - d; ++i) {
        int v = pre[i] + suf[i + d];
        if (v < mn) {
            mn = v;
            p = i + 1;
        }
        if (v > mx) {
            mx = v;
            q = i + 1;
        }
    }
    cout << p << " " << q << "\n";
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