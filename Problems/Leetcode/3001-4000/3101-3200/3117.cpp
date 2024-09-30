#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

/*
    LeetCode 对 map<tuple<int,int,int>, int> 的直接下标访问好像有点问题。（2024.8.16）
*/

class Solution {
public:
    int minimumValueSum(const vector<int>& nums, const vector<int>& andValues) {
        const int n = nums.size(), m = andValues.size();

        const int inf = INT_MAX / 2;
        map<tuple<int, int, int>, int> memo;
        auto dfs = [&](auto&& self, int i, int j, int and_) -> int {
            if (n - i < m - j) {
                return inf;
            }
            if (j == m) {
                return i == n ? 0 : inf;
            }

            and_ &= nums[i];

            auto [it, ok] = memo.emplace(tuple(i, j, and_), inf);
            int& res = it->second;
            if (ok == 0) {
                return res;
            }

            res = self(self, i + 1, j, and_);
            if (and_ == andValues[j]) {
                res = min(res, self(self, i + 1, j + 1, -1) + nums[i]);
            }
            return res;
        };

        const int ans = dfs(dfs, 0, 0, -1);
        return ans == inf ? -1 : ans;
    }
};

int main() {
    Solution sol;

    return 0;
}