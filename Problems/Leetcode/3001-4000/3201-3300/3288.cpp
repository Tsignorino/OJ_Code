#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    int maxPathLength(vector<vector<int>>& coordinates, int k) {
        int kx = coordinates[k][0], ky = coordinates[k][1];

        // 纵坐标从大到小排序之后，保证了每个 x 至多选择一个 y 值
        ranges::sort(coordinates, [&](auto& p, auto& q) { return p[0] < q[0] || p[0] == q[0] && p[1] > q[1]; });

        vector<int> g;
        for (auto& vec : coordinates) {
            int x = vec[0], y = vec[1];
            if (x < kx && y < ky || x > kx && y > ky) {
                auto iter = ranges::lower_bound(g, y);
                if (iter == g.end()) {
                    g.emplace_back(y);
                } else {
                    *iter = y;
                }
            }
        }
        return g.size() + 1;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> coordinates {
        {0, 0},
        {0, 2},
        {1, 1},
        {3, 3}
    };
    cout << sol.maxPathLength(coordinates, 3);

    return 0;
}