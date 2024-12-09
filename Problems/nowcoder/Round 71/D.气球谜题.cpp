// Date: 2024-12-09  星期一

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<int> a(n);
    for (int& x : a) {
        cin >> x;
    }

    const ll inf = numeric_limits<ll>::max();

    ll ans = inf;
    vector<int> ord {0, 1, 2};
    do {
        vector dp(n + 1, vector<ll>(3, inf));
        dp[0] = {0, 0, 0};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k <= j; k++) {
                    dp[i + 1][ord[j]] = min(dp[i + 1][ord[j]], dp[i][ord[k]] + (s[i] - '0' != ord[j]) * a[i]);
                }
            }
        }
        ans = min(ans, ranges::min(dp[n]));
    } while (ranges::next_permutation(ord).found);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}