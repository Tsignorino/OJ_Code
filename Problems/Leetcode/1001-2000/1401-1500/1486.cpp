#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    int xorOperation(int n, int start) {
        //* 性质：4i ^ (4i+1) ^ (4i+2) ^ (4i+3) = 0

        function<int(int)> func = [&](int x) -> int { // 0 ^ 1 ^ ... ^ x-1
            if (x % 4 == 0) {
                return x;
            } else if (x % 4 == 1) {
                return 1;
            } else if (x % 4 == 2) {
                return x + 1;
            } else {
                return 0;
            }
        };

        int lastBit = n & start & 1;
        int s = start >> 1;
        int preBits = func(s + n - 1) ^ func(s - 1);
        return preBits << 1 | lastBit;
    }
};