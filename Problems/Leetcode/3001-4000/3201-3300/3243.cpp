#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> g(n);
        for (int i = 0; i < n - 1; ++i) {
            g[i].emplace_back(i + 1);
        }

        vector<int> ans;
        for (auto& v : queries) {
            g[v[0]].emplace_back(v[1]);

            // BFS
            deque<int> q;
            q.emplace_back(0);
            vector<int> dis(n, -1);
            dis[0] = 0; // 标记并记录距离
            while (!q.empty()) {
                int x = q.front();
                q.pop_front();
                if (x == n - 1) {
                    ans.emplace_back(dis[x]);
                    break;
                }

                for (int& y : g[x]) {
                    if (dis[y] != -1) {
                        continue;
                    }
                    dis[y] = dis[x] + 1;
                    q.emplace_back(y);
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