#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pre(n + 1);
        for (int i = 0; i < n; ++i) {
            pre[i + 1] = (pre[i] + nums[i]) % k;
        }

        set<int> set;
        for (int i = 2; i <= n; ++i) {
            set.insert(pre[i - 2]);
            if (set.contains(pre[i])) {
                return true;
            }
        }
        return false;
    }

public:
    bool checkSubarraySum_1(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < 2) {
            return false;
        }

        unordered_map<int, int> ump;
        ump[0] = -1; // 存放下标
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum = (sum + nums[i]) % k;
            if (ump.contains(sum)) {
                if (i - ump[sum] >= 2) {
                    return true;
                }
            } else {
                ump[sum] = i;
            }
        }
        return false;
    }
};

int main() {
    Solution sol;

    return 0;
}