#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());

        vector<int> ans(2);
        for (int x : nums1) {
            ans[0] += set2.count(x);
        }
        for (int x : nums2) {
            ans[1] += set1.count(x);
        }
        return ans;
    }
};

int main() {
    Solution sol;

    return 0;
}