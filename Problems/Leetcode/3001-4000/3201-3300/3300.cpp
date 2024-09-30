#include <bits/stdc++.h>

#include "_debug.h"

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

class Solution {
public:
    int minElement(vector<int>& nums) {
        int mn = numeric_limits<int>::max();
        for (int v : nums) {
            int res = 0;
            while (v) {
                res += v % 10;
                v /= 10;
            }
            mn = min(mn, res);
        }
        return mn;
    }
};

int main() {
    Solution sol;

    return 0;
}