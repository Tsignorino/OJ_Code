#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
private:
    static constexpr int mask = 0x5555;

public:
    vector<int> evenOddBit(int n) {
        // int even = 0, odd = 0;
        // bool flag = true;
        // while (n) {
        //     if (flag) {
        //         even += n & 1;
        //         flag = false;
        //     } else {
        //         odd += n & 1;
        //         flag = true;
        //     }
        //     n >>= 1;
        // }
        // return {even, odd};

        // vector<int> ans {0, 0};
        // for (int i = 0; n; i ^= 1, n >>= 1) {
        //     ans[i] += n & 1;
        // }
        // return ans;

        //* 位掩码 + 库函数
        return {__popcount(n & mask), __popcount(n & (mask >> 1))};
    }
};