#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    s.insert(s.begin(), '.');

    vector<vector<int>> dp(n + 1, vector<int>(3));
    for (int i = 1; i <= n; ++i) {
        if (s[i] == 'R') {
            dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]);
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + 1;
            dp[i][2] = INT_MIN / 2;
        }
        if (s[i] == 'P') {
            dp[i][0] = INT_MIN / 2;
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]);
            dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + 1;
        }
        if (s[i] == 'S') {
            dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]) + 1;
            dp[i][1] = INT_MIN / 2;
            dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]);
        }
    }
    cout << ranges::max(dp[n]) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}