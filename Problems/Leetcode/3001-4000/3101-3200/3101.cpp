#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            int len = 1;
            while (i < n - 1 && nums[i] != nums[i + 1]) {
                len++, i++;
            }

            ans += len * 1ll * (len + 1) / 2;
        }
        
        // long long cnt = 0;
        // for (int i = 0; i < n; ++i) {
        //     (i && nums[i] == nums[i - 1]) ? cnt = 1 : cnt++;
        //     ans += cnt;
        // }

        return ans;
    }
};

int main() {
    vector<int> nums {0, 1, 1, 1};

    Solution sol;
    cout << sol.countAlternatingSubarrays(nums);

    return 0;
}