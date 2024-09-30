#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    static constexpr int mod = 1e9 + 7;

public:
    int countGoodStrings(int low, int high, int zero, int one) {
        //* 记忆化搜索
        // 直接返回 res 时，需要判断 i < 0; 加上判断条件的 res 就不需要了
        // vector<int> memo(high + 1, -1);
        // function<int(int)> f = [&](int i) -> int {
        //     // if (i < 0) {
        //     //     return 0;
        //     // }
        //     if (i == 0) {
        //         return 1;
        //     }

        //     int& res = memo[i];
        //     if (res != -1) {
        //         return res;
        //     }

        //     // return res = (f(i - zero) + f(i - one)) % mod;

        //     int cnt = 0;
        //     if (i >= one) {
        //         cnt = (cnt + f(i - one)) % mod;
        //     }
        //     if (i >= zero) {
        //         cnt = (cnt + f(i - zero)) % mod;
        //     }

        //     return res = cnt;
        // };

        // int ans = 0;
        // for (int i = low; i <= high; ++i) {
        //     ans = (ans + f(i)) % mod;
        // }
        // return ans;

        //* 递推
        int ans = 0;
        vector<int> f(high + 1);
        f[0] = 1;

        for (int i = 1; i <= high; ++i) {
            if (i >= one) {
                f[i] = (f[i] + f[i - one]) % mod;
            }
            if (i >= zero) {
                f[i] = (f[i] + f[i - zero]) % mod;
            }

            if (i >= low) {
                ans = (ans + f[i]) % mod;
            }
        }

        return ans;
    }
};

int main() {
    int low = 3, high = 3, zero = 1, one = 1;
    Solution sol;
    sol.countGoodStrings(low, high, zero, one);

    return 0;
}