#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    int closestCost(vector<int>& b, vector<int>& t, int target) {
        int x = ranges::min(b); // 最小基料
        if (x >= target) {
            return x;
        }

        vector<int> vec(target + 1); // 某一个开销是否存在制作方案
        int res = 2 * target - x;
        for (int& v : b) {
            if (v <= target) {
                vec[v] = 1;
            } else {
                res = min(res, v);
            }
        }
        for (int& v : t) {
            for (int T = 0; T < 2; ++T) {
                for (int i = target; i > 0; --i) {
                    if (vec[i] && i + v > target) {
                        res = min(res, i + v);
                    }
                    if (i > v) {
                        vec[i] |= vec[i - v];
                    }
                }
            }
        }

        for (int i = 0; i <= res - target; ++i) {
            if (vec[target - i]) {
                return target - i;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;

    return 0;
}