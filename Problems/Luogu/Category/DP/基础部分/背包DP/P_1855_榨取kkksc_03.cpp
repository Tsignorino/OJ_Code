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
    for (auto& v : vec) {
        cin >> v[0] >> v[1];
    }

    vector dp(tot + 1, vector<int>(t + 1));
    for (auto& v : vec) {
        for (int j = tot; j >= v[0]; --j) {
            for (int k = t; k >= v[1]; --k) {
                dp[j][k] = max(dp[j][k], dp[j - v[0]][k - v[1]] + 1);
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