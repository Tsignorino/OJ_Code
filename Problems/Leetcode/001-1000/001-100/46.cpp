#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> vec;
        vector<int> check(n);

        function<void(int)> f = [&](int i) -> void {
            if (i == n) {
                ans.emplace_back(vec);
                return;
            }

            for (int j = 0; j < n; ++j) {
                if (check[j] == 0) {
                    vec.emplace_back(nums[j]);
                    check[j] = 1;
                    f(i + 1);
                    vec.pop_back();
                    check[j] = 0;
                }
            }
        };

        f(0);
        return ans;
    }
};