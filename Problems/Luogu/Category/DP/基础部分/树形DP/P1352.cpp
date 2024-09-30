#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    vector<vector<int>> g(n);
    vector<int> isRoot(n, 1);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[b].emplace_back(a);
        isRoot[a] = 0;
    }

    vector f(n, vector<int>(2));
    function<void(int)> dfs = [&](int x) -> void {
        f[x][0] = 0, f[x][1] = vec[x];
        for (int& y : g[x]) {
            dfs(y);
            f[x][0] += max(f[y][0], f[y][1]);
            f[x][1] += f[y][0];
        }
    };

    int mx = 0;
    int s = 0;
    for (int i = 0; i < n; ++i) {
        if (isRoot[i]) {
            s = i;
            break;
        }
    }
    dfs(s);
    cout << max(f[s][0], f[s][1]) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}