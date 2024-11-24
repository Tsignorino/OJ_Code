#include <bits/stdc++.h>

#include "debug.h"

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

class Solution {
public:
    long long maximumTotalSum(vector<int>& maximumHeight) {
        ranges::sort(maximumHeight, greater<>());

        long long ans = 0;
        int mh = maximumHeight[0] + 1;
        for (int h : maximumHeight) {
            mh = min(mh - 1, h);
            if (mh <= 0) {
                return -1;
            }
            ans += mh;
        }
        return ans;
    }
};

int main() {
    Solution sol;

    return 0;
}