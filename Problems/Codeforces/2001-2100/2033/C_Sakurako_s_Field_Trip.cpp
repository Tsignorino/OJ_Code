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
    for (int& v : vec) {
        cin >> v;
    }

    for (int r = n / 2 + 1, l = n - 1 - r; r < n; --l, ++r) {
        int p = (vec[l] == vec[l + 1]) + (vec[r] == vec[r - 1]);
        int q = (vec[r] == vec[l + 1]) + (vec[l] == vec[r - 1]);
        if (p > q) {
            swap(vec[l], vec[r]);
        }
    }

    int ans = 0;
    for (int i = 0; i < n - 1; ++i) {
        ans += vec[i] == vec[i + 1];
    }
    cout << ans << "\n";
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