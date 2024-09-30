#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        int m = to_string(nums[0]).size();
        vector<vector<int>> vec(m, vector<int>(10));
        long long ans = 0;
        for (int& num : nums) {
            string s = to_string(num);
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < 10; ++j) {
                    if (j != s[i] - '0') {
                        ans += vec[i][j];
                    }
                }
                vec[i][s[i] - '0']++;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    return 0;
}