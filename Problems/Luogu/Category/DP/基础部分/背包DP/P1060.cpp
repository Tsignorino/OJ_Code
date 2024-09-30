#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int tot, n;
    cin >> tot >> n;
    vector vec(n, vector<int>(2));
    for (int i = 0; i < n; ++i) {
        cin >> vec[i][0] >> vec[i][1];
    }

    vector<int> dp(tot + 1);
    for (int i = 0; i < n; ++i) {
        for (int j = tot; j >= vec[i][0]; --j) {
            dp[j] = max(dp[j], dp[j - vec[i][0]] + vec[i][0] * vec[i][1]);
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