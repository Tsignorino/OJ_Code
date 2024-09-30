#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> vec(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> vec[i];
    }

    // 修改的数最少 --> 不修改的数最多
    // 两个数不被修改的前提是 vec[j] - vec[i] >= j - i  <==>  vec[j] - j >= vec[i] - i  （最长不下降子序列）
    vector<int> res(n + 2);
    for (int i = 1; i <= n; ++i) {
        res[i] = vec[i] - i;
    }

    //* 最长不下降子序列可能有多个
    vector<vector<int>> f(n + 1);
    vector<int> record(n + 2); // 每个数最长的以其结尾的不下降子序列长度
    vector<int> tmp; // 记录最长不下降子序列
    for (int i = 1; i <= n; ++i) {
        auto iter = ranges::upper_bound(tmp, res[i]);
        int len = 0;
        if (iter == tmp.end()) {
            tmp.emplace_back(res[i]);
            len = tmp.size();
        } else {
            *iter = res[i];
            len = iter - tmp.begin() + 1;
        }
        f[len].emplace_back(i);
        record[i] = len;
    }
    cout << n - tmp.size() << "\n";

    // 使 vec 单调上升的代价就等于使 res 单调不降的代价
    //* https://www.luogu.com.cn/article/h5fep0tq
    f[0].emplace_back(0);
    res[0] = INT_MIN / 2, res[n + 1] = INT_MAX / 2;
    record[n + 1] = tmp.size() + 1;

    // dp[i] = min(dp[j] + cost(k))
    vector<ll> dp(n + 5, LLONG_MAX / 2);
    dp[0] = 0;
    vector<ll> pre1(n + 2), pre2(n + 2); // 记录两个前缀和，用以计算 cost(k)
    for (int i = 1; i <= n + 1; ++i) {
        for (int p = 0; p < f[record[i] - 1].size(); ++p) {
            int j = f[record[i] - 1][p];
            if (j > i || res[j] > res[i]) {
                continue;
            }

            pre1[i] = pre2[j] = 0;
            for (int q = i - 1; q > j; --q) {
                pre1[q] = pre1[q + 1] + abs(res[q] - res[i]);
            }
            for (int q = j + 1; q < i; ++q) {
                pre2[q] = pre2[q - 1] + abs(res[q] - res[j]);
            }

            ll ans = LLONG_MAX / 2;
            for (int k = j; k < i; ++k) {
                ans = min(ans, pre1[k + 1] + pre2[k]);
            }
            dp[i] = min(dp[i], dp[j] + ans);
        }
    }

    cout << dp[n + 1] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
