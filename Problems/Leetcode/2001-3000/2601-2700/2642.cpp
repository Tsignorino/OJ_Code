#include <bits/stdc++.h>

using namespace std;

class Graph {
private:
    vector<vector<pair<int, int>>> g;

public:
    Graph(int n, vector<vector<int>>& edges) : g(n) {
        for (vector<int>& e : edges) {
            g[e[0]].emplace_back(e[1], e[2]);
        }
    }

    void addEdge(vector<int> edge) { g[edge[0]].emplace_back(edge[1], edge[2]); }

    int shortestPath(int node1, int node2) {
        vector<int> dis(g.size(), INT_MAX);
        dis[node1] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
        q.emplace(0, node1);
        while (!q.empty()) {
            auto [d, x] = q.top();
            q.pop();

            if (x == node2) {
                return d;
            }
            if (d > dis[x]) {
                continue;
            }

            for (auto& [y, w] : g[x]) {
                if (d + w < dis[y]) {
                    dis[y] = d + w;
                    q.emplace(dis[y], y);
                }
            }
        }

        return -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */