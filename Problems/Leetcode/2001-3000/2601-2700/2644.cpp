#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        int ans = divisors[0];
        int res = 0;
        for (int& v : divisors) {
            int cnt = 0;
            for (int& num : nums) {
                cnt += num % v == 0;
            }

            if (cnt > res || cnt == res && v < ans) {
                res = cnt;
                ans = v;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    return 0;
}