#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/*
    ! 每个主件最多只有两个
*/

void solve() {
    int m, n;
    cin >> m >> n;
    vector<vector<pair<int, int>>> vec(n, vector<pair<int, int>>(2)); // ! 注意数据读入
    for (int i = 0; i < n; ++i) {
        int w, v, p;
        cin >> w >> v >> p;

        if (p == 0) {
            vec[i][0] = pair(w, v);
        } else {
            vec[p - 1].insert(vec[p - 1].begin() + 1, pair(w, v));
        }
    }

    vector<int> dp(m + 1);
    for (auto& res : vec) {
        res.resize(3);
        for (int j = m; j >= 0; --j) {
            if (j >= res[0].first) {
                dp[j] = max(dp[j], dp[j - res[0].first] + res[0].first * res[0].second);
            }
            if (j >= res[0].first + res[1].first) {
                dp[j] = max(dp[j], dp[j - res[0].first - res[1].first] + res[0].first * res[0].second + res[1].first * +res[1].second);
            }
            if (j >= res[0].first + res[2].first) {
                dp[j] = max(dp[j], dp[j - res[0].first - res[2].first] + res[0].first * res[0].second + res[2].first * +res[2].second);
            }
            if (j >= res[0].first + res[1].first + res[2].first) {
                dp[j] = max(dp[j], dp[j - res[0].first - res[1].first - res[2].first] + res[0].first * res[0].second + res[1].first * res[1].second + res[2].first * res[2].second);
            }
        }
    }
    cout << dp[m] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}