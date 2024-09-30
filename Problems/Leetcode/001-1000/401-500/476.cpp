#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    int findComplement(int num) { //* [1, 2^31)
        // int n = 32 - __builtin_clz(num);
        // return num ^ ((1LL << n) - 1);

        // int high = 0;
        // for (int i = 1; i <= 30; ++i) {
        //     if (num >= (1 << i)) {
        //         high = i;
        //     } else {
        //         break;
        //     }
        // }
        // int mask = high == 30 ? 0x7fffffff : (1 << (high + 1)) - 1;
        // return num ^ mask;

        //* 观察最高位 1
        int n = num;
        n |= n >> 1;
        n |= n >> 2;
        n |= n >> 4;
        n |= n >> 8;
        n |= n >> 16;
        return ~num & n;
    }
};