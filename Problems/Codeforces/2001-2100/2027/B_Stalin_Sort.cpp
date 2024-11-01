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

    // 第一项需要是最大值
    int ans = n;
    for (int i = 0; i < n; ++i) {
        int res = 0;
        for (int j = i + 1; j < n; ++j) {
            if (vec[j] > vec[i]) {
                res++;
            }
        }
        ans = min(ans, res + i);
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