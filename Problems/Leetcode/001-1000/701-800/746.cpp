#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        //* 记忆化搜索
        // int n = cost.size();

        // vector<int> memo(n + 1, -1);
        // function<int(int)> f = [&](int i) -> int {
        //     if (i <= 1) {
        //         return 0;
        //     }

        //     int& res = memo[i];
        //     if (res != -1) {
        //         return res;
        //     }

        //     return res = min(f(i - 1) + cost[i - 1], f(i - 2) + cost[i - 2]);
        // };

        // return f(n);

        //* 递推
        // int n = cost.size();
        // vector<int> f(n + 1);
        // for (int i = 2; i <= n; ++i) {
        //     f[i] = min(f[i - 1] + cost[i - 1], f[i - 2] + cost[i - 2]);
        // }
        // return f[n];

        int n = cost.size();
        int f0 = 0, f1 = 0;
        // for (int i = 2; i < n + 1; ++i) {
        //     int f2 = min(f1 + cost[i - 1], f0 + cost[i - 2]);

        //     f0 = f1;
        //     f1 = f2;
        // }
        for (int i = 1; i < n; ++i) {
            int f2 = min(f1 + cost[i], f0 + cost[i - 1]);

            f0 = f1;
            f1 = f2;
        }
        return f1;
    }
};