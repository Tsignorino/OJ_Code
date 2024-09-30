#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

struct Node {
    int t, d, l;
};

void solve() {
    int n;
    cin >> n;
    vector<Node> vec(n);
    for (auto& [t, d, l] : vec) {
        cin >> t >> d >> l;
    }

    vector<int> vis(n);

    function<bool(int, int)> dfs = [&](int cnt, int time) -> bool {
        if (cnt >= n) {
            return true;
        }

        for (int i = 0; i < n; ++i) {
            if (vis[i] || vec[i].t + vec[i].d < time) {
                continue;
            }
            vis[i] = 1;
            if (dfs(cnt + 1, max(time, vec[i].t) + vec[i].l)) {
                vis[i] = 0;
                return true;
            }
            vis[i] = 0;
        }
        return false;
    };

    if (dfs(0, 0)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}