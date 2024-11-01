#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int ans = INT_MIN / 2, f0 = ans, f1 = ans;
        for (int& x : nums) {
            f1 = max(f1 + x, f0);
            f0 = max(f0, 0) + x;
            ans = max(ans, max(f0, f1));
        }
        return ans;
    }
};

int main() {
    Solution sol;

    return 0;
}