#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        int ans = 0, maxL = 0;
        vector<int> dp(n, 1), cnt(n, 1);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        cnt[i] = cnt[j];
                    } else if (dp[j] + 1 == dp[i]) {
                        cnt[i] += cnt[j];
                    }
                }
            }

            if (dp[i] > maxL) {
                maxL = dp[i];
                ans = cnt[i];
            } else if (dp[i] == maxL) {
                ans += cnt[i];
            }
        }

        return ans;
    }
};

int main() {
    vector<int> vec {1, 3, 5, 4, 7};

    Solution sol;
    sol.findNumberOfLIS(vec);

    return 0;
}