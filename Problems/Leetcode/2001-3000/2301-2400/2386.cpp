#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    long long kSum(vector<int>& nums, int k) {
        // 先求出所有非负数的和，再逐步减去一个非负数或者加上一个负数，即减去一个数的绝对值
        // 减去的数越小，nums 子序列和越大
        //* 问题转化为：把 nums[i] 取绝对值之后，第 k 小的子序列之和是多少

        ll sum = 0;
        for (int& num : nums) {
            num >= 0 ? sum += num : num *= -1;
        }
        ranges::sort(nums);

        /* 二分 + 暴搜
            auto check = [&](ll limit) -> bool {
                int cnt = 1;

                auto dfs = [&](auto self, int i, ll s) -> void {
                    if (cnt == k || i == nums.size() || s + nums[i] > limit) {
                        return;
                    }
                    cnt++;
                    self(self, i + 1, s + nums[i]);
                    self(self, i + 1, s);
                };
                dfs(dfs, 0, 0);

                return cnt == k;
            };

            ll l = -1, r = accumulate(nums.begin(), nums.end(), 0LL);
            while (l + 1 < r) {
                ll mid = l + (r - l) / 2;
                (check(mid) ? r : l) = mid;
            }

            return sum - r;
        */

        // 最小堆
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
        pq.emplace(0, 0); // 末尾元素，下一个要添加/替换的元素下标
        while (--k) {
            auto [s, i] = pq.top();
            pq.pop();

            if (i < nums.size()) {
                pq.emplace(s + nums[i], i + 1);

                if (i) {
                    pq.emplace(s + nums[i] - nums[i - 1], i + 1);
                }
            }
        }

        return sum - pq.top().first;
    }
};

int main() {
    vector<int> nums {2, 4, -2};

    Solution sol;
    cout << sol.kSum(nums, 5);

    return 0;
}