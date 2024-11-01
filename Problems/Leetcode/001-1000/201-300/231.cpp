#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        // return n > 0 && __popcount(n) == 1;

        // return n > 0 && (n & (n - 1)) == 0;

        // return n > 0 && (n & -n) == n;

        return n == 1 || n != 0 && n % 2 == 0 && isPowerOfTwo(n / 2);
    }
};