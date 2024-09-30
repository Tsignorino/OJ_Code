#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    int rob(vector<int>& nums) {
        //* 记忆化搜索
        // int n = nums.size();
        // vector<int> memo(n, -1);

        // function<int(int)> f = [&](int i) -> int {
        //     if (i < 0) {
        //         return 0;
        //     }

        //     int& res = memo[i];
        //     if (res != -1) {
        //         return res;
        //     }

        //     return res = max(f(i - 2) + nums[i], f(i - 1));
        // };

        // return f(n - 1);

        //* 递推
        // int n = nums.size();
        // vector<int> f(n + 2);

        // for (int i = 0; i < n; ++i) {
        //     f[i + 2] = max(f[i + 1], f[i] + nums[i]);
        // }

        // return f[n + 1];

        int f0 = 0, f1 = 0;

        for (const int& num : nums) {
            int f2 = max(f1, f0 + num);

            f0 = f1;
            f1 = f2;
        }

        return f1;
    }
};