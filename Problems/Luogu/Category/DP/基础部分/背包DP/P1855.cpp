#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/*
    只不过是多了一个维度
*/

void solve() {
    int n, tot, t;
    cin >> n >> tot >> t;
    vector vec(n, vector<int>(2));
    for (int i = 0; i < n; ++i) {
        cin >> vec[i][0] >> vec[i][1];
    }

    vector<vector<int>> dp(tot + 1, vector<int>(t + 1));
    for (int i = 0; i < n; ++i) {
        for (int j = tot; j >= vec[i][0]; --j) {
            for (int k = t; k >= vec[i][1]; --k) {
                dp[j][k] = max(dp[j][k], dp[j - vec[i][0]][k - vec[i][1]] + 1);
            }
        }
    }
    cout << dp[tot][t] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}