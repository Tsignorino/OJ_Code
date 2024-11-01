#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int tot, n;
    cin >> tot >> n;

    vector vec(n, vector<int>(2));
    for (auto& v : vec) {
        cin >> v[0] >> v[1];
    }

    vector<int> dp(tot + 1);
    for (auto& v : vec) {
        for (int j = tot; j >= v[0]; --j) {
            dp[j] = max(dp[j], dp[j - v[0]] + v[0] * v[1]);
        }
    }
    cout << dp[tot] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}