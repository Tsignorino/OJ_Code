#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0, ans = 0;
        unordered_map<int, int> ump; // 统计前缀和的出现次数
        for (const int& num : nums) {
            sum += num;
            ans += ump[sum - k];
            ump[sum]++;
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums {1, 1, 1};
    sol.subarraySum(nums, 2);

    return 0;
}