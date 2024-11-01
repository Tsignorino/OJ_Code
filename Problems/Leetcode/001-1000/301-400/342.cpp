#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    bool isPowerOfFour(int n) {
        //* 1 后面有偶数个 0
        // return n > 0 && (n & (n - 1)) == 0 && __builtin_ctz(n) % 2 == 0;

        //* 1 必须出现在奇数位
        // return n > 0 && (n & (n - 1)) == 0 && (n & 0xaaaaaaaa) == 0;

        //* 取模性质
        return n > 0 && (n & (n - 1)) == 0 && n % 3 == 1;
    }
};