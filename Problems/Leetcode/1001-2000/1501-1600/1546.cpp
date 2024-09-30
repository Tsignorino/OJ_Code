#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            unordered_set<int> set {0};
            int sum = 0;
            while (i < n) {
                sum += nums[i];
                if (set.find(sum - target) != set.end()) {
                    ans++;
                    break;
                } else {
                    set.insert(sum);
                    i++;
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    return 0;
}