#include <bits/stdc++.h>

using namespace std;

class DSU { // Implement (union by size) + (path compression)
private:
    int n;
    vector<int> pa, Size;

public:
    DSU(int n) : n(n), pa(n), Size(n, 1) { iota(pa.begin(), pa.end(), 0); }

    int find(int x) {
        assert(x >= 0 && x < n);
        return x == pa[x] ? x : pa[x] = find(pa[x]);
    }

    void merge(int x, int y) {
        assert(x >= 0 && x < n), assert(y >= 0 && y < n);
        int px = find(x), py = find(y);
        if (px == py) {
            return;
        }
        if (Size[px] > Size[py]) {
            swap(px, py);
        }
        pa[px] = py;
        Size[py] += Size[px];
    }

    int size(int x) {
        assert(x >= 0 && x < n);
        return Size[find(x)];
    }
};

// DSU
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> Idx;
        unordered_map<string, string> Name;

        int cnt = 0;
        for (auto& account : accounts) {
            for (int i = 1; i < account.size(); ++i) {
                string& email = account[i];
                if (!Idx.contains(email)) {
                    Idx[email] = cnt++;
                    Name[email] = account[0];
                }
            }
        }

        DSU dsu(cnt);
        for (auto& account : accounts) {
            for (int i = 2; i < account.size(); ++i) {
                dsu.merge(Idx[account[1]], Idx[account[i]]);
            }
        }

        unordered_map<int, vector<string>> ump;
        for (auto& [email, v] : Idx) {
            int idx = dsu.find(v);

            vector<string>& account = ump[idx];
            account.emplace_back(email);
            ump[idx] = account;
        }

        vector<vector<string>> ans;
        for (auto& [_, emails] : ump) {
            vector<string> account {Name[emails[0]]};
            ranges::sort(emails);
            for (string& email : emails) {
                account.emplace_back(email);
            }
            ans.emplace_back(account);
        }
        return ans;
    }
};

// dfs
class Solution_2 {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        unordered_map<string, vector<int>> ump;
        for (int i = 0; i < n; ++i) {
            for (int k = 1; k < accounts[i].size(); ++k) {
                ump[accounts[i][k]].emplace_back(i);
            }
        }

        unordered_set<string> set;
        vector<int> vis(n);
        function<void(int)> dfs = [&](int i) -> void {
            vis[i] = 1;
            for (int k = 1; k < accounts[i].size(); ++k) {
                string& email = accounts[i][k];
                if (set.contains(email)) {
                    continue;
                }
                set.emplace(email);
                for (int j : ump[email]) {
                    if (vis[j] == 0) {
                        dfs(j);
                    }
                }
            }
        };

        vector<vector<string>> ans;
        for (int i = 0; i < n; ++i) {
            if (vis[i] == 1) {
                continue;
            }
            set.clear();
            dfs(i);

            vector<string> res {accounts[i][0]};
            res.insert(res.end(), set.begin(), set.end());
            sort(res.begin() + 1, res.end());

            ans.emplace_back(res);
        }
        return ans;
    }
};

int main() {
    Solution sol;

    return 0;
}