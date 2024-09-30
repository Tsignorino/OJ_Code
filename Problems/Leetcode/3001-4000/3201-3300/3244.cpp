#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    // 用并查集实现边的合并（并查集的节点表示 i->i+1 这条边）
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> pa(n - 1);
        iota(pa.begin(), pa.end(), 0);

        function<int(int)> find = [&](int x) {
            return x == pa[x] ? x : pa[x] = find(pa[x]);
        };

        vector<int> ans;
        int cnt = n - 1;
        for (auto& q : queries) {
            int l = q[0], r = q[1] - 1; // 把 l, l+1, l+2, ... , r-2 都连到 r-1 上
            int root = find(r);
            for (int i = find(l); i < r; i = find(i + 1)) {
                pa[i] = root;
                cnt--;
            }
            ans.emplace_back(cnt);
        }
        return ans;
    }

public:
    // set 去边
    vector<int> shortestDistanceAfterQueries_1(int n, vector<vector<int>>& queries) {
        set<pair<int, int>> s;
        for (int i = 0; i < n - 1; ++i) {
            s.emplace(i, i + 1);
        }

        vector<int> ans;
        for (auto& q : queries) {
            int u = q[0], v = q[1];

            auto iter = s.lower_bound({u, -1});
            if (iter != s.end() && iter->second < v) {
                for (; iter != s.end() && iter->second <= v;) {
                    iter = s.erase(iter);
                }
                s.emplace(u, v);
            }

            ans.emplace_back(s.size());
        }
        return ans;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> vec {
        {1, 4},
        {2, 4},
    };
    sol.shortestDistanceAfterQueries(5, vec);

    return 0;
}