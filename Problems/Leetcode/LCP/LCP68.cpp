#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    static constexpr int mod = 1e9 + 7;

public:
    int beautifulBouquet(vector<int>& nums, int cnt) {
        long long ans = 0;
        int n = nums.size();
        unordered_map<int, int> ump;

        for (int l = 0, r = 0; r < n; ++r) {
            ump[nums[r]]++;

            while (ump[nums[r]] > cnt) {
                ump[nums[l++]]--;
            }

            ans += r - l + 1;
        }

        return ans % mod;
    }
};

int main() {
    Solution sol;

    vector<int> flowers {1, 2, 3, 2};
    int cnt = 1;
    cout << sol.beautifulBouquet(flowers, cnt);

    return 0;
}