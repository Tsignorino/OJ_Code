#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        //* 递归 —— 枚举选哪个
        // int n = nums.size();
        // function<int(int)> dfs = [&](int i) -> int {
        //     if (i == 0) {
        //         return nums[0];
        //     }

        //     int s = INT_MIN;
        //     for (int j = max(i - k, 0); j < i; ++j) {
        //         s = max(s, dfs(j));
        //     }

        //     return s + nums[i];
        // };

        // return dfs(n - 1);

        //* 递推
        // int n = nums.size();
        // vector<int> f(n);
        // f[0] = nums[0];
        // for (int i = 1; i < n; ++i) {
        //     f[i] = *max_element(f.begin() + max(i - k, 0), f.begin() + i) + nums[i];
        // }
        // return f[n - 1];

        //* 单调队列
        int n = nums.size();
        vector<int> f(n);
        f[0] = nums[0];
        deque<int> q = {0}; // 存放下标
        for (int i = 1; i < n; ++i) {
            if (q.front() < i - k) {
                q.pop_front();
            }

            f[i] = f[q.front()] + nums[i];

            while (!q.empty() && f[i] >= f[q.back()]) {
                q.pop_back();
            }

            q.emplace_back(i);
        }
        return f[n - 1];
    }
};