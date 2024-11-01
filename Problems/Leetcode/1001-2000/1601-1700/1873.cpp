#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> stk;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int x = nums[i];
            while (!stk.empty() && x < stk.back() && stk.size() + n - i > k) {
                stk.pop_back();
            }
            if (stk.size() < k) {
                stk.emplace_back(x);
            }
        }
        return stk;
    }
};

int main() {
    Solution sol;

    return 0;
}