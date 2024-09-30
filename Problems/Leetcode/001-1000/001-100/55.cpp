#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int mx = 0;
        for (int i = 0; mx < nums.size() - 1; i++) { //  mx ≥ n−1 时就返回 true
            if (i > mx) {
                return false;
            }
            mx = max(mx, i + nums[i]); // 从 i 最右可以跳到 i + nums[i]
        }
        return true;
    }
};

int main() {
    Solution sol;

    return 0;
}