#include <bits/stdc++.h>

#include "debug.h"

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

class Solution {
public:
    bool judgeSquareSum(int c) { // 找到一个数的所有质因数
        map<int, int> prifac;

        for (int i = 2; i * 1ll * i <= c; ++i) {
            while (c % i == 0) {
                c /= i;
                prifac[i]++;
            }
        }
        if (c > 1) {
            prifac[c]++;
        }

        for (auto& [v, c] : prifac) {
            if (c % 2 == 1) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution sol;

    return 0;
}