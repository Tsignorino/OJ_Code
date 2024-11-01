#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        //* （病毒扩散）
        int n = nums.size();
        unordered_map<int, vector<int>> ump;
        for (int i = 0; i < n; ++i) {
            ump[nums[i]].emplace_back(i);
        }

        int ans = n;
        for (const auto& p : ump) {
            int max_dis = p.second.front() + n - p.second.back();
            for (int i = 1; i < p.second.size(); ++i) {
                max_dis = max(max_dis, p.second[i] - p.second[i - 1]);
            }

            ans = min(ans, max_dis / 2);
        }

        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> nums {1, 2, 1, 2};
    cout << sol.minimumSeconds(nums);

    return 0;
}