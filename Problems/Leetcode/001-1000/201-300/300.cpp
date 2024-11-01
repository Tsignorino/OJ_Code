#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    //* 记忆化搜索
    int lengthOfLIS_0(vector<int>& nums) {
        int n = nums.size();

        vector<int> memo(n);
        function<int(int)> dfs = [&](int i) -> int {
            int& res = memo[i];
            if (res) {
                return res;
            }

            for (int j = i - 1; j >= 0; --j) {
                if (nums[j] < nums[i]) {
                    res = max(res, dfs(j));
                }
            }
            return ++res;
        };

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, dfs(i));
        }
        return ans;
    }

public:
    //* 递推
    int lengthOfLIS_1(vector<int>& nums) {
        int n = nums.size();

        vector<int> f(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    f[i] = max(f[i], f[j]);
                }
            }
            ++f[i];
        }

        return ranges::max(f);
    }

public:
    //* 贪心 + 二分
    // 以当前元素为末尾元素，能够得到的最长递增子序列 -> 以当前长度为准，末尾元素的最小值
    int lengthOfLIS_2(vector<int>& nums) {
        //* g 数组严格递增，一次只更新一个值，该值为第一个不小于 x 的数
        vector<int> g;
        for (const int& x : nums) {
            auto iter = ranges::lower_bound(g, x);
            if (iter == g.end()) {
                g.emplace_back(x);
            } else {
                *iter = x;
            }
        }
        return g.size();
    }
};