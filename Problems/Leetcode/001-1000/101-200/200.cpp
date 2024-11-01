#include <bits/stdc++.h>

using namespace std;

class UnionFind {
private:
    vector<int> parent, rank;
    int cnt;

public:
    UnionFind(vector<vector<char>>& grid) {
        cnt = 0;

        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    parent.emplace_back(i * n + j);
                    cnt++;
                } else {
                    parent.emplace_back(-1);
                }

                rank.emplace_back(0);
            }
        }
    }

    int find(int i) {
        if (parent[i] != i) {
            parent[i] = find(parent[i]);
        }
        return parent[i];
    }

    void unite(int x, int y) {
        int rootx = find(x), rooty = find(y);
        if (rootx != rooty) {
            if (rank[rootx] < rank[rooty]) {
                swap(rootx, rooty);
            }

            parent[rooty] = rootx;

            if (rank[rootx] == rank[rooty]) {
                rank[rootx] += 1;
            }
            cnt--;
        }
    }

    int getCount() { return cnt; }
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        // 扫描整个二位网格，从 1 开始 DFS
        int n = grid.size(), m = grid[0].size();
        int cnt = 0;

        //* 并查集
        UnionFind uf(grid);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '1') {
                    grid[i][j] = '0';

                    if (i > 0 && grid[i - 1][j] == '1') {
                        uf.unite(i * m + j, (i - 1) * m + j);
                    }
                    if (i + 1 < n && grid[i + 1][j] == '1') {
                        uf.unite(i * m + j, (i + 1) * m + j);
                    }
                    if (j > 0 && grid[i][j - 1] == '1') {
                        uf.unite(i * m + j, i * m + j - 1);
                    }
                    if (j + 1 < m && grid[i][j + 1] == '1') {
                        uf.unite(i * m + j, i * m + j + 1);
                    }
                }
            }
        }
        return uf.getCount();

        //* DFS
        // auto dfs = [&](auto self, int x, int y) -> void {
        //     grid[x][y] = '0';

        //     if (x > 0 && grid[x - 1][y] == '1') {
        //         self(self, x - 1, y);
        //     }
        //     if (x + 1 < n && grid[x + 1][y] == '1') {
        //         self(self, x + 1, y);
        //     }
        //     if (y > 0 && grid[x][y - 1] == '1') {
        //         self(self, x, y - 1);
        //     }
        //     if (y + 1 < m && grid[x][y + 1] == '1') {
        //         self(self, x, y + 1);
        //     }
        // };

        // for (int i = 0; i < n; ++i) {
        //     for (int j = 0; j < m; ++j) {
        //         if (grid[i][j] == '1') {
        //             dfs(dfs, i, j);
        //             cnt++;
        //         }
        //     }
        // }
        // return cnt;

        //* BFS
        // for (int i = 0; i < n; ++i) {
        //     for (int j = 0; j < m; ++j) {
        //         if (grid[i][j] == '1') {
        //             cnt++;
        //             grid[i][j] = '0';

        //             queue<pair<int, int>> q;
        //             q.emplace(i, j);
        //             while (!q.empty()) {
        //                 auto tmp = q.front();
        //                 q.pop();

        //                 int x = tmp.first, y = tmp.second;
        //                 if (x > 0 && grid[x - 1][y] == '1') {
        //                     q.emplace(x - 1, y);
        //                     grid[x - 1][y] = '0';
        //                 }
        //                 if (x + 1 < n && grid[x + 1][y] == '1') {
        //                     q.emplace(x + 1, y);
        //                     grid[x + 1][y] = '0';
        //                 }
        //                 if (y > 0 && grid[x][y - 1] == '1') {
        //                     q.emplace(x, y - 1);
        //                     grid[x][y - 1] = '0';
        //                 }
        //                 if (y + 1 < m && grid[x][y + 1] == '1') {
        //                     q.emplace(x, y + 1);
        //                     grid[x][y + 1] = '0';
        //                 }
        //             }
        //         }
        //     }
        // }
        // return cnt;
    }
};