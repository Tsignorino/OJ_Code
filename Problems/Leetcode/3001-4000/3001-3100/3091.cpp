#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minOperations(int k) {
        int minV = 1e9;
        // for (int i = 0; i <= k / 2; ++i) {
        //     minV = min(minV, max(0, k - 1) / (i + 1) + i);
        // }
        for (int m = 1; m <= k; ++m) {
            minV = min(minV, m - 1 + (k - 1) / m);
        }
        return minV;
    }
};