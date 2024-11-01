#include <bits/stdc++.h>

using namespace std;

class Solution {
    static constexpr int MOD = 1e9 + 7;

public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        // f[i][j][k] 表示 “考虑前 i 件物品，使用人数不超过 j，所得利润至少为 k”
        /*
            状态定义的时候，利润维度可能出现负数，“利润至少为某个负数 k” 等价于 “利润至少为 0”
        */
        vector f = vector<vector<int>>(n + 1, vector<int>(minProfit + 1));
        for (int i = 0; i <= n; ++i) {
            f[i][0] = 1;
        }
        for (int i = 0; i < group.size(); ++i) {
            int v = group[i];
            for (int j = n; j >= v; --j) {
                for (int k = minProfit; k >= 0; --k) {
                    f[j][k] = (f[j][k] + f[j - v][max(k - profit[i], 0)]) % MOD;
                }
            }
        }
        return f[n][minProfit];
    }
};

int main() {
    Solution sol;

    return 0;
}