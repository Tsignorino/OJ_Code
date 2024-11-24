#include <bits/stdc++.h>

#include "debug.h"

using namespace std;

static constexpr int MOD = 1'000'000'007;

class Solution {
public:
    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        vector f(op1 + 1, vector<int>(op2 + 1));
        for (int x : nums) {
            for (int p = op1; p >= 0; p--) {
                for (int q = op2; q >= 0; q--) {
                    int res = f[p][q] + x;
                    if (p) {
                        res = min(res, f[p - 1][q] + (x + 1) / 2);
                    }
                    if (q && x >= k) {
                        res = min(res, f[p][q - 1] + x - k);
                        if (p) {
                            int y = (x - k + 1) / 2;
                            if ((x + 1) / 2 >= k) {
                                y = min(y, (x + 1) / 2 - k);
                            }
                            res = min(res, f[p - 1][q - 1] + y);
                        }
                    }
                    f[p][q] = res;
                }
            }
        }
        return f[op1][op2];
    }
};

int main() {
    Solution sol;

    return 0;
}