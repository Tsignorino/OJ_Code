#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> loss_count;
        for (auto& m : matches) {
            // if (!loss_count.contains(m[0])) {
            //     loss_count[m[0]] = 0;
            // }
            loss_count[m[0]];
            loss_count[m[1]]++;
        }

        vector<vector<int>> ans(2);
        for (auto& [player, cnt] : loss_count) {
            if (cnt < 2) {
                ans[cnt].push_back(player);
            }
        }
        ranges::sort(ans[0]);
        ranges::sort(ans[1]);
        return ans;
    }
};

int main() {
    Solution sol;

    return 0;
}