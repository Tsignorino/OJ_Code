#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    // int countCompleteSubarrays(vector<int>& nums) {
    //     int n = nums.size();
    //     unordered_map<int, int> ump;
    //     for (int& num : nums) {
    //         ump[num]++;
    //     }
    //     int cnt = ump.size();
    //     ump.clear();

    //     int ans = 0, diff = 0;
    //     for (int l = 0, r = 0; r < n; ++r) {
    //         if (++ump[nums[r]] == 1) {
    //             diff++;
    //         }

    //         while (diff == cnt) {
    //             ans += n - r;

    //             if (--ump[nums[l]] == 0) {
    //                 diff--;
    //             }
    //             l++;
    //         }
    //     }

    //     return ans;
    // }

    //* 小优化：去掉 n 的定义，统计符合条件的左端点
    int countCompleteSubarrays(vector<int>& nums) {
        int diff = unordered_set<int>(nums.begin(), nums.end()).size();
        unordered_map<int, int> ump;

        int ans = 0, l = 0;
        for (int& num : nums) {
            if (++ump[num] == 1) {
                diff--;
            }

            while (diff == 0) {
                if (--ump[nums[l]] == 0) {
                    diff++;
                }
                l++;
            }

            ans += l;
        }

        return ans;
    }

    // int countCompleteSubarrays(vector<int>& nums) {
    //     int m = unordered_set<int>(nums.begin(), nums.end()).size();
    //     unordered_map<int, int> ump;

    //     int ans = 0, l = 0;
    //     for (int& num : nums) {
    //         ump[num]++;

    //         while (ump.size() == m) {
    //             if (--ump[nums[l]] == 0) {
    //                 ump.erase(nums[l]);
    //             }
    //             l++;
    //         }

    //         ans += l;
    //     }

    //     return ans;
    // }
};

int main() {
    Solution sol;

    vector<int> nums {1, 1, 1, 1};
    cout << sol.countCompleteSubarrays(nums);

    return 0;
}