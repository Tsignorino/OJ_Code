#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int n = nums.size(), m = pattern.size();
        vector<int> s(n - 1);
        for (int i = 0; i < n - 1; ++i) {
            s[i] = (nums[i + 1] > nums[i]) - (nums[i + 1] < nums[i]);
        }

        int ans {};
        for (int i = 0; i < n - m; ++i) {
            bool flag = true;

            for (int k = i; k < i + m; ++k) {
                if (s[k] != pattern[k - i]) {
                    flag = false;
                }
            }

            ans += flag;
        }

        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> nums {1, 2, 3, 4, 5, 6};
    vector<int> pattern {1, 1};
    cout << sol.countMatchingSubarrays(nums, pattern);

    return 0;
}