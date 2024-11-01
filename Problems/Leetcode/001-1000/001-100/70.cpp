#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    int climbStairs(int n) {
        //* 记忆化搜索
        // int ans = 0;
        // vector<int> memo(n + 1, -1);
        // function<int(int)> f = [&](int i) -> int {
        //     if (i <= 1) {
        //         return 1;
        //     }

        //     int& res = memo[i];
        //     if (res != -1) {
        //         return res;
        //     }

        //     return res = f(i - 1) + f(i - 2);
        // };

        // return f(n);

        //* 递推
        // vector<int> f(n + 1, 1);
        // for (int i = 2; i < n + 1; ++i) {
        //     f[i] = f[i - 1] + f[i - 2];
        // }
        // return f[n];

        int f0 = 1, f1 = 1;
        for (int i = 2; i < n + 1; ++i) {
            int f2 = f1 + f0;

            f0 = f1;
            f1 = f2;
        }
        return f1;
    }
};