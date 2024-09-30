#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n);
        int ans = 0;
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                q.emplace(i);
                while (!q.empty()) {
                    int x = q.front();
                    q.pop();
                    vis[x] = 1;
                    for (int y = 0; y < n; ++y) {
                        if (isConnected[x][y] == 1 && !vis[y]) {
                            q.emplace(y);
                        }
                    }
                }
                ans++;
            }
        }
        return ans;
    }
};

class Solution_1 {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n);

        function<void(int)> dfs = [&](int i) -> void {
            for (int j = 0; j < n; ++j) {
                if (isConnected[i][j] == 1 && !vis[j]) {
                    vis[j] = 1;
                    dfs(j);
                }
            }
        };

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                dfs(i);
                ans++;
            }
        }
        return ans;
    }
};

class Solution_2 {
private:
    vector<int> pa;

    int find(int x) { return x == pa[x] ? x : pa[x] = find(pa[x]); }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        pa.resize(n);
        iota(pa.begin(), pa.end(), 0);

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (isConnected[i][j] == 1) {
                    pa[find(i)] = find(j);
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += pa[i] == i; // 统计连通分量的个数
        }
        return ans;
    }
};