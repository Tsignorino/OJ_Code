#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        // M(initial) 表示整个网络中被感染的节点数，返回移除的某个节点
        // 当连通块中没有被感染的节点，移除连通块内的任何节点都不会使 M 减小
        // 当连通块中有至少两个被感染的节点，同样不会使 M 减小
        // 因此，需要寻找只包含一个被感染的节点的连通块！
        int n = graph.size();
        set<int> s(initial.begin(), initial.end());
        vector<int> vis(n);
        int ans = -1, maxV = 0, status, size;

        // 连通块内有一个/多个被感染的节点
        // -1：初始状态
        // x：找到一个，x 为该节点
        // -2：找到多个

        auto dfs = [&](auto self, int x) -> void {
            vis[x] = 1;
            size++;

            if (status != -2 && s.contains(x)) {
                status = status == -1 ? x : -2;
            }
            for (int y = 0; y < graph[x].size(); ++y) {
                if (graph[x][y] && !vis[y]) {
                    self(self, y);
                }
            }
        };

        for (int x : initial) {
            if (vis[x]) {
                continue;
            }

            status = -1;
            size = 0;
            dfs(dfs, x);
            if (status >= 0 && (size > maxV || size == maxV && status < ans)) {
                ans = status;
                maxV = size;
            }
        }

        return ans == -1 ? ranges::min(initial) : ans;
    }
};