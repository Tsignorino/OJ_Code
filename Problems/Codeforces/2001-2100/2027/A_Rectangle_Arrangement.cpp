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

    int W = 0, H = 0;
    for (int i = 0; i < n; ++i) {
        int w, h;
        cin >> w >> h;
        W = max(W, w);
        H = max(H, h);
    }
    cout << (W + H) * 2 << "\n";
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