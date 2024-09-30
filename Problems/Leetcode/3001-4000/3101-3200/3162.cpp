#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int ans = 0;
        for (int& num : nums1) {
            for (int& v : nums2) {
                if (num % (v * k) == 0) {
                    ans++;
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