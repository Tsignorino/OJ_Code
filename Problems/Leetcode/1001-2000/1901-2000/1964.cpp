#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& nums) {
        // 你可以选择下标介于 0 到 i 之间（包含 0 和 i）的任意个障碍。
        // 在这条路线中，必须包含第 i 个障碍。
        // 你必须按障碍在 nums 中的 出现顺序 布置这些障碍。
        // 非递减
        vector<int> ans, f;
        for (const int& num : nums) {
            auto iter = ranges::upper_bound(f, num);

            if (iter == f.end()) {
                f.emplace_back(num);
                ans.emplace_back(f.size());
            } else {
                *iter = num;
                ans.emplace_back(iter - f.begin() + 1);
            }
        }

        return ans;
    }
};