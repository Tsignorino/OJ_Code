#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class BFS {
private:
    vector<vector<int>> edges; // 存图
    vector<int> in; // 入度
    vector<int> ans;

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        in.resize(numCourses);
        for (const auto& v : prerequisites) {
            edges[v[1]].emplace_back(v[0]);
            in[v[0]]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (in[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int u = q.front();
            ans.emplace_back(u);
            q.pop();
            for (int v : edges[u]) {
                if (--in[v] == 0) {
                    q.push(v);
                }
            }
        }

        return ans.size() == numCourses ? ans : vector<int>();
    }
};

class DFS {
private:
    vector<vector<int>> edges; // 存图
    vector<int> status; // 0 - 未搜索，1 - 搜索中，2 - 已搜索
    // stack<int> stk;
    vector<int> ans; // 数组模拟栈
    bool valid = true; // 判断是否有环

public:
    void dfs(int u) {
        status[u] = 1;

        for (int v : edges[u]) {
            if (status[v] == 0) {
                dfs(v);
                if (!valid) {
                    return;
                }
            } else if (status[v] == 1) {
                valid = false;
                return;
            }
        }

        status[u] = 2;

        // stk.push(u);
        ans.emplace_back(u);
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        status.resize(numCourses);
        for (const auto& v : prerequisites) {
            edges[v[1]].emplace_back(v[0]);
        }

        for (int i = 0; i < numCourses && valid; ++i) {
            if (status[i] == 0) {
                dfs(i);
            }
        }

        if (valid == false) {
            return {};
        }

        // vector<int> ans;
        // while (!stk.empty()) {
        //     ans.emplace_back(stk.top());
        //     stk.pop();
        // }

        ranges::reverse(ans);

        return ans;
    }
};

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // BFS sol_0;
        // return sol_0.findOrder(numCourses, prerequisites);

        DFS sol_1;
        return sol_1.findOrder(numCourses, prerequisites);
    }
};