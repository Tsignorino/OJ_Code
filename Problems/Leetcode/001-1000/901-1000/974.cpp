#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> ump;
        int ans = 0, sum = 0;
        for (int num : nums) {
            ump[(sum % k + k) % k]++;
            sum += num;
            ans += ump[(sum % k + k) % k];
        }
        return ans;
    }
};

int main() {
    Solution sol;

    return 0;
}