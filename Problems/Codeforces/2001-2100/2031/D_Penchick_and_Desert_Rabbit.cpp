#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int& v : a) {
        cin >> v;
    }

    vector<int> suf(a);
    for (int i = n - 2; i >= 0; --i) {
        suf[i] = min(suf[i + 1], a[i]);
    }

    for (int i = 0; i < n;) {
        int j = i;
        int mx = a[i];
        for (i++; i < n && mx > suf[i]; ++i) {
            mx = max(mx, a[i]);
        }
        for (; j < i; ++j) {
            cout << mx << " ";
        }
    }
    cout << "\n";
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