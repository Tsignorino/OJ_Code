#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    vector<vector<int>> subsets_0(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> vec;
        int n = nums.size();
        function<void(int)> f = [&](int i) -> void {
            // 边界条件
            if (i == n) {
                ans.emplace_back(vec);
                return;
            }

            // 选
            vec.emplace_back(nums[i]);
            f(i + 1);
            vec.pop_back(); // 恢复现场

            // 不选
            f(i + 1);
        };

        f(0);
        return ans;
    }

    vector<vector<int>> subsets_1(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> vec;
        int n = nums.size();
        function<void(int)> f = [&](int i) -> void {
            ans.emplace_back(vec);

            // 枚举选哪个
            for (int j = i; j < n; ++j) {
                vec.emplace_back(nums[j]);
                f(j + 1);
                vec.pop_back();
            }
        };

        f(0);
        return ans;
    }
};
