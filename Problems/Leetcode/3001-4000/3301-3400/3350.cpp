#include <bits/stdc++.h>

#include "debug.h"

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();

        int ans = 1;
        vector<int> vec;
        for (int i = 0, j = i; i < n; i = j + 1) {
            for (j = i; j < n - 1 && nums[j] < nums[j + 1]; ++j);
            vec.push_back(j - i + 1);
            ans = max(ans, (j - i + 1) / 2);
        }
        for (int i = 1; i < vec.size(); ++i) {
            ans = max(ans, min(vec[i - 1], vec[i]));
        }
        return ans;
    }
};

int main() {
    Solution sol;

    return 0;
}