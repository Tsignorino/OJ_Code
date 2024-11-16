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

    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;

        auto iter = ranges::upper_bound(ans, v);
        if (iter == ans.end()) {
            ans.emplace_back(v);
        } else {
            *iter = v;
        }
    }
    cout << n - ans.size() << "\n";
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