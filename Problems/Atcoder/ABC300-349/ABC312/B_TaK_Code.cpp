// Date: 2024-12-09  星期一

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<string> g(n);
    for (string& s : g) {
        cin >> s;
    }

    auto check = [&](int i, int j) {
        if (g[i].substr(j, 4) == "###." && g[i + 1].substr(j, 4) == "###." //
            && g[i + 2].substr(j, 4) == "###." && g[i + 3].substr(j, 4) == "...." //
            && g[i + 8].substr(j + 5, 4) == ".###" && g[i + 7].substr(j + 5, 4) == ".###" //
            && g[i + 6].substr(j + 5, 4) == ".###" && g[i + 5].substr(j + 5, 4) == "....") {
            // cout << g[i].substr(0, 4) << "\n";
            // cout << g[i + 1].substr(0, 4) << "\n";
            // cout << g[i + 2].substr(0, 4) << "\n";
            // cout << g[i + 3].substr(0, 4) << "\n";
            // cout << g[i + 5].substr(j + 5, 4) << "\n";
            // cout << g[i + 6].substr(j + 5, 4) << "\n";
            // cout << g[i + 7].substr(j + 5, 4) << "\n";
            // cout << g[i + 8].substr(j + 5, 4) << "\n";
            return true;
        }
        return false;
    };

    for (int i = 0; i + 8 < n; ++i) {
        for (int j = 0; j + 8 < m; ++j) {
            if (check(i, j)) {
                cout << i + 1 << " " << j + 1 << "\n";
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}