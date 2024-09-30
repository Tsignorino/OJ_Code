#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

/*
    每个垃圾都可以吃或者堆，可以类比背包的选或不选
    有四个值可能成为状态：高度、生命、物品、时间
    > 考虑到最优情况（奶牛在垃圾丢下来的时候就去处理），那么物品和时间相关联

    考虑：
        dp[i][j] 表示前 i 件物品处理后 j 血量时的最大高度   dp[i][j] = max(dp[i-1][j] + trash[i].h, dp[i-1][j + trash[i].c])
        （√）dp[i][j] 表示前 i 件物品处理后 h 高度时的最大血量   dp[i][j] = max(dp[i-1][j] + trash[i].c, dp[i-1][j - trash[i].h])
*/

void solve() {
    int d, n;
    cin >> d >> n;
    vector vec(n + 1, vector<int>(2));
    for (int i = 1; i <= n; ++i) {
        cin >> vec[i][0] >> vec[i][1] >> vec[i][2]; // 时间，生命值，高度
    }

    ranges::sort(vec);

    vector dp(n + 1, vector<int>(d + 1, -1));
    dp[0][0] = 10;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= d; ++j) {
            if (dp[i][j] < 0) { // 没有奶牛的状态
                continue;
            }

            // 奶牛能撑到跳出去
            if (j + vec[i + 1][2] >= d && dp[i][j] >= vec[i + 1][0] - vec[i][0]) {
                cout << vec[i + 1][0] << "\n";
                return;
            }
            if (dp[i][j] - vec[i + 1][0] + vec[i][0] >= 0) {
                dp[i + 1][j + vec[i + 1][2]] = dp[i][j] - vec[i + 1][0] + vec[i][0];
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] - vec[i + 1][0] + vec[i][0] + vec[i + 1][1]);
            }
        }
    }

    int m = 10, sum = 0;
    for (int i = 1; i <= n; ++i) {
        if (vec[i][0] - vec[i - 1][0] > m) {
            cout << sum + m << "\n";
            return;
        }
        sum += vec[i][0] - vec[i - 1][0];
        m -= vec[i][0] - vec[i - 1][0];
        m += vec[i][1];
    }
    cout << sum + m << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
