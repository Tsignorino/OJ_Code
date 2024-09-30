#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = INT_MAX;
        for (int i = 0; i < n; ++i) {
            int res = 0;
            for (int j = i; j < n; ++j) {
                res |= nums[j];
                if (res >= k) {
                    ans = min(ans, j - i + 1);
                    break;
                }
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }

public:
    int minimumSubarrayLength_1(vector<int>& nums, int k) {
        int n = nums.size();

        for (int len = 1; len <= n; ++len) {
            int ans = 0;
            for (int i = 0; i < n - len + 1; ++i) {
                int res = 0;
                for (int j = i; j < i + len; ++j) {
                    res |= nums[j];
                }
                ans = max(ans, res);

                if (ans >= k) {
                    return len;
                }
            }
        }

        return -1;
    }
};

int main() {
    vector<int> vec {2, 1, 8};

    Solution sol;
    cout << sol.minimumSubarrayLength(vec, 10);

    return 0;
}