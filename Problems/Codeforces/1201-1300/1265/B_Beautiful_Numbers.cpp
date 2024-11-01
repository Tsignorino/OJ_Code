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

    vector<int> vec(n);
    vector<int> pos(n);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
        vec[i]--;
        pos[vec[i]] = i;
    }

    // debug(pos);

    int mn = n, mx = 0;
    for (int i = 0; i < n; ++i) {
        mx = max(mx, pos[i]);
        mn = min(mn, pos[i]);
        if (mx - mn == i) {
            cout << 1;
        } else {
            cout << 0;
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