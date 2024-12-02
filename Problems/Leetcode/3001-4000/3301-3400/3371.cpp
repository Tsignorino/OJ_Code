#include <bits/stdc++.h>

#include "debug.h"

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        multiset<int> s(nums.begin(), nums.end());
        int ans = numeric_limits<int>::min();
        for (int& v : nums) {
            s.extract(v);
            sum -= v;
            if (sum % 2 == 0 && s.contains(sum / 2)) {
                ans = max(ans, v);
            }
            sum += v;
            s.emplace(v);
        }
        return ans;
    }
};

int main() {
    Solution sol;

    return 0;
}