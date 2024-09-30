#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        ranges::sort(nums);
        for (int i = 1; i < nums.size(); i += 2) {
            swap(nums[i - 1], nums[i]);
        }
        return nums;
    }
};

int main() {
    Solution sol;

    return 0;
}