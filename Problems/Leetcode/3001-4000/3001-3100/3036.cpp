#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
private:
    vector<int> z_func(vector<int> s) {
        int n = s.size();
        vector<int> z(n);

        for (int i = 1, l = 0, r = 0; i < n; ++i) {
            if (i <= r) {
                z[i] = min(z[i - l], r - i + 1);
            }
            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
                l = i, r = i + z[i]++;
            }
        }
        return z;
    }

public:
    int countMatchingSubarrays_1(vector<int>& nums, vector<int>& pattern) {
        int n = nums.size(), m = pattern.size();
        vector<int> s(pattern);
        s.emplace_back(27); // 添加分割字符
        for (int i = 0; i < n - 1; ++i) {
            // nums[i+1] > nums[i]      1
            // nums[i+1] = nums[i]      0
            // nums[i+1] < nums[i]     -1
            s.emplace_back((nums[i + 1] > nums[i]) - (nums[i + 1] < nums[i]));
        }

        vector<int> z = z_func(s);
        int ans = 0;
        for (int i = m + 1; i < z.size(); ++i) {
            ans += z[i] == m;
        }

        return ans;
    }
};