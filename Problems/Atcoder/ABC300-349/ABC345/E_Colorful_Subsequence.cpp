#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> C(n + 2), V(n + 2);
    for (int i = 1; i <= n; i++) {
        cin >> C[i] >> V[i];
    }
    C[0] = n + 1;
    C[n + 1] = n + 2;
    n += 2;

    vector dp(n, vector<ll>(k + 1, LLONG_MIN));
    dp[0][0] = 0;
    for (int s = 1; s <= n - 1 - k; s++) {
        pair<ll, int> mx[2] {
            {LLONG_MIN, 0},
            {LLONG_MIN, 0}
        };
        for (int i = s; i <= k + s; i++) {
            pair<ll, int> v {dp[i - 1][i - s], C[i - 1]};
            if (v > mx[0]) {
                swap(v, mx[0]);
            }
            if (mx[0].second == mx[1].second || (v > mx[1] && v.second != mx[0].second)) {
                mx[1] = v;
            }
            dp[i][i - s] = mx[mx[0].second == C[i]].first + V[i];
        }
    }

    cout << max(-1LL, dp[n - 1][k]) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
