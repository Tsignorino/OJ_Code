#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        // 建树时，把受限的边忽略掉
        vector<vector<int>> g(n);

        unordered_set<int> r(restricted.begin(), restricted.end());
        for (vector<int>& e : edges) {
            int x = e[0], y = e[1];
            if (!r.contains(x) && !r.contains(y)) {
                g[x].emplace_back(y);
                g[y].emplace_back(x);
            }
        }

        // auto dfs = [&](auto self, int x, int parent) -> int {
        //     int cnt = 1;
        //     for (int& y : g[x]) {
        //         if (y != parent) {
        //             cnt += self(self, y, x);
        //         }
        //     }

        //     return cnt;
        // };

        // return dfs(dfs, 0, -1);

        int res = 1;
        queue<int> q;
        q.emplace(0);
        r.insert(0);
        while (!q.empty()) {
            int ss = q.size();
            while (ss--) {
                int val = q.front();
                for (int& p : g[val]) {
                    if (r.count(p)) {
                        continue;
                    }

                    q.emplace(p);
                    r.insert(p);
                    res++;
                }

                q.pop();
            }
        }

        return res;
    }
};