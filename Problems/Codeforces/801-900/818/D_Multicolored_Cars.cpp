#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, k;
    cin >> n >> k;

    map<int, vector<int>> mp;
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;
        mp[v].push_back(i);
    }

    if (!mp.contains(k)) {
        cout << (k == 1 ? 2 : 1) << "\n";
        return;
    }

    auto& b = mp[k];
    for (auto& [v, a] : mp) {
        if (v == k || a.size() < b.size()) {
            continue;
        }

        int ok = 1;
        for (int i = 0; i < b.size(); ++i) {
            if (a[i] > b[i]) {
                ok = 0;
                break;
            }
        }
        if (ok) {
            cout << v << "\n";
            return;
        }
    }
    cout << -1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}