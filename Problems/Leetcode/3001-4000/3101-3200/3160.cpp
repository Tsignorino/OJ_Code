#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n = limit + 1;
        unordered_map<int, int> vec; // 颜色
        unordered_map<int, int> ump; // 频次
        vector<int> ans;
        for (auto& q : queries) {
            int& pre = vec[q[0]]; // 之前的颜色
            if (pre) {
                if (--ump[pre] == 0) {
                    ump.erase(pre);
                }
            }
            pre = q[1];
            ump[q[1]]++;
            ans.emplace_back(ump.size());
        }
        return ans;
    }
};

/*
    4
    [[1,4],[2,5],[1,3],[3,4]]
    预期：[1,2,2,3]

    5
    [[0,1],[0,4],[4,3],[5,5],[3,1]]

    爆内存
*/

int main() {
    Solution sol;

    vector<vector<int>> vec {
        {0, 1},
        {0, 4},
        {4, 3},
        {5, 5},
        {3, 1}
    };
    sol.queryResults(5, vec);

    return 0;
}