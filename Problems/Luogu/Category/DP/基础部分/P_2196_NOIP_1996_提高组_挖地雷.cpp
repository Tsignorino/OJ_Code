#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

// #include "_debug.h"

void solve() {
    int n;
    cin >> n;

    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int v;
            cin >> v;

            if (v == 1) {
                g[i].emplace_back(j);
                g[j].emplace_back(i);
            }
        }
    }

    // 一条路径挖下去
    vector<int> f(n), pre(n, -1);
    for (int i = 0; i < n; i++) {
        for (int j : g[i]) {
            if (f[j] > f[i]) {
                f[i] = f[j];
                pre[i] = j;
            }
        }
        f[i] += vec[i];
    }
    // debug(f);

    vector<int> res;
    int end = find(f.begin(), f.end(), ranges::max(f)) - f.begin();
    while (true) {
        res.emplace_back(end);
        end = pre[end];

        if (end == -1) {
            break;
        }
    }

    int ans = 0;
    for (int i = res.size() - 1; i >= 0; --i) {
        ans += vec[res[i]];
        cout << res[i] + 1 << " \n"[i == 0];
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}