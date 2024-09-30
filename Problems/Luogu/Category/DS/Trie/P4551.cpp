#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

/*
    4
    1 2 3
    2 3 4
    2 4 6

->  1 -> 1  000
    1 -> 2  011
    1 -> 3  111
    1 -> 4  101
*/

class Trie {
private:
    Trie* children[2] {};

public:
    Trie() = default;

    void insert(int val) {
        Trie* node = this;
        for (int k = 30; k >= 0; --k) {
            if (node->children[val >> k & 1] == nullptr) {
                node->children[val >> k & 1] = new Trie();
            }
            node = node->children[val >> k & 1];
        }
    }

    int query(int val) {
        Trie* node = this;
        int res = 0;
        for (int k = 30; k >= 0; --k) {
            int b = val >> k & 1;
            if (node->children[b ^ 1] == nullptr) {
                node = node->children[b];
            } else {
                node = node->children[b ^ 1];
                res += 1 << k;
            }
        }
        return res;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> vec(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        vec[u].emplace_back(v, w);
    }

    vector<int> res(n + 1);
    function<void(int, int)> dfs = [&](int x, int val) -> void {
        for (auto& [v, w] : vec[x]) {
            res[v] = val ^ w;
            dfs(v, res[v]);
        }
    };

    dfs(1, 0);

    Trie trie;
    for (int i = 1; i <= n; ++i) {
        trie.insert(res[i]);
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans = max(ans, trie.query(res[i]));
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}