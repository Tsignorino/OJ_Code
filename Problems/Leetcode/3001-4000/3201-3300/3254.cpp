#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> q;
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            while (!q.empty() && nums[q.back()] + 1 != nums[i]) {
                q.pop_back();
            }
            q.emplace_back(i);
            if (q.front() <= i - k) {
                q.pop_front();
            }
            if (i >= k - 1) {
                ans.emplace_back(q.size() == k ? nums[q.back()] : -1);
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    return 0;
}