#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans = 1;
        int i = 0, n = nums.size();
        while (i < n - 1) {
            // pass
            if (nums[i + 1] == nums[i]) {
                i++;
                continue;
            }

            int start = i;
            bool flag = nums[i + 1] > nums[i]; // 奠定基调
            i += 2; // 当前位置和下一位置已满足
            while (i < n && nums[i] != nums[i - 1] && (nums[i] > nums[i - 1]) == flag) {
                i++;
            }

            ans = max(ans, i - start);
            i--;
        }
        return ans;
    }

public:
    int my_longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (nums[j] > nums[j - 1]) {
                    ans = max(ans, j - i + 1);
                } else {
                    break;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (nums[j] < nums[j - 1]) {
                    ans = max(ans, j - i + 1);
                } else {
                    break;
                }
            }
        }
        return ans;
    }
};

int main() {
    vector<int> nums {3, 2, 1};
    Solution sol;
    cout << sol.longestMonotonicSubarray(nums);
    return 0;
}