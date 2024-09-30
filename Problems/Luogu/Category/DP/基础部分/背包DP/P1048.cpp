#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/*
    采药
*/

void solve() {
    int t, n;
    cin >> t >> n;
    vector vec(n, vector<int>(2));
    for (int i = 0; i < n; ++i) {
        cin >> vec[i][0] >> vec[i][1];
    }

    vector<int> dp(t + 1);
    for (int i = 0; i < n; ++i) {
        for (int j = t; j >= vec[i][0]; --j) {
            dp[j] = max(dp[j], dp[j - vec[i][0]] + vec[i][1]);
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