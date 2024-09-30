#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> pre(n);
        for (int i = 0; i < n - 1; ++i) {
            pre[i + 1] = pre[i] + (nums[i + 1] % 2 != nums[i] % 2);
        }

        vector<bool> ans;
        for (auto& q : queries) {
            int i = q[0], j = q[1];
            // cout << pre[j] <<" " << pre[i] << "\n";
            ans.emplace_back(pre[j] - pre[i] == j - i);
        }
        return ans;
    }
};

int main() {
    Solution sol;

    return 0;
}