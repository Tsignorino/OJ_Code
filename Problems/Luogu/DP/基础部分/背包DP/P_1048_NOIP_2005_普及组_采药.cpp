#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int t, n;
    cin >> t >> n;

    vector vec(n, vector<int>(2));
    for (auto& v : vec) {
        cin >> v[0] >> v[1];
    }

    vector<int> dp(t + 1);
    for (auto& v : vec) {
        for (int j = t; j >= v[0]; --j) {
            dp[j] = max(dp[j], dp[j - v[0]] + v[1]);
        }
    }
    cout << dp[t] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}