#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution_0 {
public:
    int numSquares(int n) {
        int k = 1;
        for (; k * k <= n; ++k) {} // 1, ..., k-1

        // // vector<int> nums(k - 1);
        // // iota(nums.begin(), nums.end(), 1);

        //* 记忆化搜索
        // vector<vector<int>> memo(k, vector<int>(n + 1, -1));
        // function<int(int, int)> dfs = [&](int i, int s) -> int {
        //     if (i < 0) {
        //         return s == 0 ? 0 : INT_MAX / 2;
        //     }

        //     int& res = memo[i][s];
        //     if (res != -1) {
        //         return res;
        //     }

        //     // if (s < nums[i] * nums[i]) {
        //     //     return dfs(i - 1, s);
        //     // }
        //     // return min(dfs(i - 1, s), dfs(i, s - nums[i] * nums[i]) + 1);
        //     if (s < (i + 1) * (i + 1)) {
        //         return res = dfs(i - 1, s);
        //     }
        //     return res = min(dfs(i - 1, s), dfs(i, s - (i + 1) * (i + 1)) + 1);
        // };

        // return dfs(k - 2, n);

        //* 递推
        // vector<vector<int>> f(k, vector<int>(n + 1, INT_MAX / 2));
        // f[0][0] = 0;

        // for (int i = 0; i < k - 1; ++i) {
        //     for (int s = 0; s <= n; ++s) {
        //         if (s < (i + 1) * (i + 1)) {
        //             f[i + 1][s] = f[i][s];
        //         } else {
        //             f[i + 1][s] = min(f[i][s], f[i + 1][s - (i + 1) * (i +
        //             1)] + 1);
        //         }
        //     }
        // }

        // return f[k - 1][n];

        vector<int> f(n + 1, INT_MAX / 2);
        f[0] = 0;
        for (int i = 0; i < k - 1; ++i) {
            for (int s = (i + 1) * (i + 1); s <= n; ++s) {
                f[s] = min(f[s], f[s - (i + 1) * (i + 1)] + 1);
            }
        }

        return f[n];

        //* 官解 Official solution
        // vector<int> f(n + 1);
        // for (int i = 1; i <= n; i++) {
        //     int minn = INT_MAX;
        //     for (int j = 1; j * j <= i; j++) {
        //         minn = min(minn, f[i - j * j]);
        //     }
        //     f[i] = minn + 1;
        // }
        // return f[n];
    }
};

class Solution_1 {
public:
    // 判断是否为完全平方数
    bool isPerfectSquare(int x) {
        int y = sqrt(x);
        return y * y == x;
    }

    // 判断是否能表示为 4^k*(8m+7)
    bool checkAnswer4(int x) {
        while (x % 4 == 0) {
            x /= 4;
        }
        return x % 8 == 7;
    }

    int numSquares(int n) {
        if (isPerfectSquare(n)) {
            return 1;
        }
        if (checkAnswer4(n)) {
            return 4;
        }
        for (int i = 1; i * i <= n; i++) {
            int j = n - i * i;
            if (isPerfectSquare(j)) {
                return 2;
            }
        }
        return 3;
    }
};