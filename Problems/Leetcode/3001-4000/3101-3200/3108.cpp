#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<vector<pair<int, int>>> g;
    vector<int> cc_and, ids;

    int dfs(int x) {
        ids[x] = cc_and.size();
        int and_ = -1;
        for (auto& [y, w] : g[x]) {
            and_ &= w;
            if (ids[y] < 0) { // 没有访问过
                and_ &= dfs(y);
            }
        }
        return and_;
    }

public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        g.resize(n);
        for (auto& e : edges) {
            int x = e[0], y = e[1], w = e[2];
            g[x].emplace_back(y, w);
            g[y].emplace_back(x, w);
        }

        ids.resize(n, -1);
        for (int i = 0; i < n; ++i) {
            if (ids[i] < 0) {
                cc_and.emplace_back(dfs(i));
            }
        }

        vector<int> ans;
        ans.reserve(query.size());
        for (auto& q : query) {
            int s = q[0], t = q[1];
            int v1 = ids[s], v2 = ids[t];
            ans.emplace_back(s == t ? 0 : v1 == v2 ? cc_and[v1] : -1);
        }
        return ans;
    }

private:
    vector<int> pa, and_;

    int find(int x) { return pa[x] = pa[x] != x ? find(pa[x]) : x; }

public:
    vector<int> minimumCost_1(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        pa.resize(n);
        iota(pa.begin(), pa.end(), 0);
        and_.resize(n, -1);

        for (vector<int>& edge : edges) {
            int x = find(edge[0]), y = find(edge[1]);
            and_[y] &= edge[2];
            if (x != y) {
                and_[y] &= and_[x];
                pa[x] = y;
            }
        }

        vector<int> ans;
        for (vector<int>& q : query) {
            int s = q[0], t = q[1];
            int v1 = find(s), v2 = find(t);
            ans.emplace_back(s == t ? 0 : v1 == v2 ? and_[v1] : -1);
        }
        return ans;
    }
};

class UnionFind {
public:
    vector<int> pa, and_val;

    UnionFind(int size) : pa(size), and_val(size, -1) { iota(pa.begin(), pa.end(), 0); }

    int find(int x) { return pa[x] == x ? x : pa[x] = find(pa[x]); }

    void unite(int x, int y, int w) {
        int rootX = find(x), rootY = find(y);
        pa[rootY] = rootX;
        and_val[rootX] &= and_val[rootY] & w;
    }
};

class mySolution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        UnionFind uf(n);

        for (vector<int>& edge : edges) {
            uf.unite(edge[0], edge[1], edge[2]);
        }

        vector<int> ans;
        for (vector<int>& query : queries) {
            if (query[0] == query[1]) {
                ans.push_back(0);
                continue;
            }

            int x = uf.find(query[0]);
            int y = uf.find(query[1]);
            if (x == y) {
                ans.emplace_back(uf.and_val[x]);
            } else {
                ans.push_back(-1);
            }
        }

        return ans;
    }
};
