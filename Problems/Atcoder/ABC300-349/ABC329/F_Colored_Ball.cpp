#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, q;
    cin >> n >> q;

    vector<set<int>> vec(n);
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;
        vec[i].emplace(v);
    }

    while (q--) {
        int a, b;
        cin >> a >> b;
        a--, b--;

        if (vec[a].size() > vec[b].size()) {
            swap(vec[a], vec[b]);
        }
        for (int x : vec[a]) {
            vec[b].emplace(x);
        }
        vec[a].clear();
        cout << vec[b].size() << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}