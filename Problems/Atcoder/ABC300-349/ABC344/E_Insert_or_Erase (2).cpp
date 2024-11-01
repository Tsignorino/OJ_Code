#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;

    vector<int> vec(n + 1);
    map<int, vector<int>> tree;
    map<int, int> pos;
    for (int i = 1; i <= n; ++i) {
        cin >> vec[i];
        pos[vec[i]] = i;
        tree[0].emplace_back(i);
    }

    ranges::reverse(tree[0]);

    int q;
    cin >> q;
    set<int> rm {0};
    while (q--) {
        int Op;
        cin >> Op;
        if (Op == 1) {
            int x, y;
            cin >> x >> y;
            tree[pos[x]].emplace_back(pos[y] = vec.size());
            vec.emplace_back(y);
        } else {
            int x;
            cin >> x;
            rm.emplace(pos[x]);
        }
    }

    auto dfs = [&](auto&& self, int u) -> void {
        if (!rm.contains(u)) {
            cout << vec[u] << " ";
        }
        for (int v : tree[u] | views::reverse) {
            self(self, v);
        }
    };

    dfs(dfs, 0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}