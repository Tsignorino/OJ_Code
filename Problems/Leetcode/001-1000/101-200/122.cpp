#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // int n = prices.size();

        // vector<vector<int>> memo(n, vector<int>(2, -1));
        // function<int(int, bool)> dfs = [&](int i, bool hold) -> int {
        //     if (i == -1) {
        //         return hold ? INT_MIN / 2 : 0;
        //     }

        //     int& res = memo[i][hold];
        //     if (res != -1) {
        //         return res;
        //     }

        //     if (hold) {
        //         return res = max(dfs(i - 1, true), dfs(i - 1, false) - prices[i]);
        //     }
        //     return res = max(dfs(i - 1, false), dfs(i - 1, true) + prices[i]);
        // };

        // return dfs(n - 1, false);

        int f0 = 0, f1 = INT_MIN;
        for (int p : prices) {
            int new_f0 = max(f0, f1 + p);
            f1 = max(f1, f0 - p);
            f0 = new_f0;
        }
        return f0;
    }
};
