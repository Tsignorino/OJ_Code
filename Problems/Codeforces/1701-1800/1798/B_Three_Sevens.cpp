#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> vec(n);
    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        int m;
        cin >> m;
        vec[i].resize(m);
        for (int& v : vec[i]) {
            cin >> v;
            mp[v] = i;
        }
    }

    vector<int> ans(n, -1);
    for (int i = 0; i < n; ++i) {
        for (int& v : vec[i]) {
            if (mp[v] == i) {
                ans[i] = v;
                break;
            }
        }
        if (ans[i] == -1) {
            cout << -1 << "\n";
            return;
        }
    }

    for (int& v : ans) {
        cout << v << " ";
    }
    cout << "\n";
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