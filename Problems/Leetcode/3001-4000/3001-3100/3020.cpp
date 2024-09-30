#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> ump;
        for (const int& num : nums) {
            ump[num]++;
        }

        //* 特判
        int ans = ump[1] - (ump[1] % 2 ^ 1);
        ump.erase(1);

        for (const auto& [num, _] : ump) {
            int res = 0;
            long long x = num;
            for (; ump.contains(x) && ump[x] > 1; x *= x) {
                res += 2;
            }
            ans = max(ans, res + (ump.contains(x) ? 1 : -1));
        }

        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> nums {5, 4, 1, 2, 2};
    cout << sol.maximumLength(nums);

    return 0;
}