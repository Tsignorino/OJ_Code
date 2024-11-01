#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int n = meetings.size();
        ranges::sort(meetings);
        vector<vector<int>> vec {meetings[0]};
        int pre = vec.back()[1];
        for (int i = 1; i < n; ++i) {
            if (meetings[i][0] > pre) {
                vec.emplace_back(meetings[i]);
            } else {
                vec.back()[1] = max(vec.back()[1], meetings[i][1]);
            }
            pre = vec.back()[1];
        }

        int res = 0;
        for (auto& v : vec) {
            res += v[1] - v[0] + 1;
            // cout << v[0] << " " << v[1] << "\n";
        }
        return days - res;
    }
};

int main() {
    Solution sol;

    return 0;
}