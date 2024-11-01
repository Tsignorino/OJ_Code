#include <bits/stdc++.h>

using namespace std;

constexpr int MOD = 1e9 + 7;

class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();

        // vector<int> s(n + 1);
        // for (int i = 0; i < n; ++i) {
        //     s[i + 1] = s[i] ^ nums[i];
        // }
        // 
        // unordered_map<int, int> ump;
        // for (int x : s) {
        //     ans += ump[x]++;
        // }

        int s = 0;
        unordered_map<int, int> ump {
            {s, 1}
        };
        for (int x : nums) {
            s ^= x;
            ans += ump[s]++;
        }
        return ans;
    }
};

int main() {
    Solution sol;

    return 0;
}