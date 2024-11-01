#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;

    // vector<int> vec(n);
    // for (int& v : vec) {
    //     cin >> v;
    // }
    //
    // vector dp(n + 1, vector<ll>(2));
    // dp[0][1] = LLONG_MIN / 2;
    // for (int i = 0; i < n; ++i) {
    //     dp[i + 1][0] = max(dp[i][0], dp[i][1] + 2 * vec[i]);
    //     dp[i + 1][1] = max(dp[i][1], dp[i][0] + vec[i]);
    // }
    // cout << ranges::max(dp[n]) << "\n";

    ll a = 0, b = LLONG_MIN / 2;
    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
        tie(a, b) = tie(max(a, b + 2 * v), max(b, a + v));
    }
    cout << max(a, b) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}