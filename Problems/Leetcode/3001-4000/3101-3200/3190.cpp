#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans = 0;
        for (int num : nums) {
            if (num % 3) {
                ans++;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    return 0;
}