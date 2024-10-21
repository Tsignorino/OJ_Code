#include <bits/stdc++.h>

#include "debug.h"

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

vector<int> manacher(string& s) {
    int m = s.size() * 2 + 1;
    string t(m, ' ');
    for (int i = 0, j = 0; i < m; ++i) {
        t[i] = i & 1 ? s[j++] : '#';
    }

    vector<int> Len(m);
    for (int i = 0, c = 0, r = 0; i < m; ++i) {
        int len = r > i ? min(Len[2 * c - i], r - i) : 1;
        while (i + len <= m && i - len >= 0 && t[i - len] == t[i + len]) {
            len++;
        }
        if (i + len > r) {
            r = i + len;
            c = i;
        }
        Len[i] = len;
    }
    return Len;
} // 返回值为真实回文串长度 +1

class Solution {
public:
    vector<bool> findAnswer(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> g(n);
        for (int i = 1; i < n; ++i) {
            g[parent[i]].emplace_back(i);
        }

        string res(n, ' ');
        vector<array<int, 2>> nodes(n);
        int clk = 0;
        auto dfs = [&](auto&& dfs, int x = 0) -> void {
            nodes[x][0] = clk;
            for (int y : g[x]) {
                dfs(dfs, y);
            }
            res[clk++] = s[x];
            nodes[x][1] = clk;
        };
        dfs(dfs);

        // debug(res);
        // debug(nodes);

        auto Len = manacher(res);
        // debug(Len);
        auto isPalindrome = [&](int l, int r) { // 左闭右开
            return Len[l + r] > r - l;
        };

        vector<bool> ans;
        for (auto& [l, r] : nodes) {
            ans.emplace_back(isPalindrome(l, r));
        }
        // debug(ans);
        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> parent {-1, 0, 0, 1, 1, 2};
    sol.findAnswer(parent, "aababa");

    return 0;
}