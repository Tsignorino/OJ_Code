#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    // int longestSubarray(vector<int>& nums, int limit) {
    //     int n = nums.size(), ans = 0;
    //     deque<int> qMax, qMin;

    //     for (int l = 0, r = 0; r < n; ++r) {
    //         while (!qMax.empty() && qMax.back() < nums[r]) {
    //             qMax.pop_back();
    //         }
    //         while (!qMin.empty() && qMin.back() > nums[r]) {
    //             qMin.pop_back();
    //         }

    //         qMax.emplace_back(nums[r]);
    //         qMin.emplace_back(nums[r]);

    //         while (!qMax.empty() && !qMin.empty() && qMax.front() - qMin.front() > limit) {
    //             if (nums[l] == qMax.front()) {
    //                 qMax.pop_front();
    //             }
    //             if (nums[l] == qMin.front()) {
    //                 qMin.pop_front();
    //             }

    //             l++;
    //         }

    //         ans = max(ans, r - l + 1);
    //     }

    //     return ans;
    // }

    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size(), ans = 0;
        multiset<int> s;
        for (int l = 0, r = 0; r < n; ++r) {
            s.insert(nums[r]);

            while (*s.rbegin() - *s.begin() > limit) {
                s.erase(s.find(nums[l++]));
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> nums {8, 2, 4, 7};
    int limit = 4;

    cout << sol.longestSubarray(nums, limit);

    return 0;
}