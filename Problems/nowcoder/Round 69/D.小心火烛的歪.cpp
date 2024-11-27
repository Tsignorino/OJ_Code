// Date: 2024-11-27  星期三

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<string> meadow(n);
    for (auto& s : meadow) {
        cin >> s;
    }

    vector plans(q, vector<string>(n));
    for (int i = 0; i < q; ++i) {
        for (auto& s : plans[i]) {
            cin >> s;
        }
    }

    const int N = 10;
    vector<int> ans(N, 1);
    for (int i = 0; i < (1 << q); ++i) {
        vector tmp(n, string(m, '0'));
        vector<int> choose(q);
        for (int j = 0; j < q; ++j) {
            if ((i >> j) & 1) {
                choose[j] = 1;
                for (int x = 0; x < n; ++x) {
                    for (int y = 0; y < m; ++y) {
                        if (plans[j][x][y] == '1') {
                            tmp[x][y] = '1';
                        }
                    }
                }
            }
        }

        int ok = 1;
        for (int x = 0; x < n; ++x) {
            for (int y = 0; y < m; ++y) {
                if (meadow[x][y] == tmp[x][y]) {
                    ok = 0;
                    break;
                }
            }
            if (ok == 0) {
                break;
            }
        }
        if (ok) {
            vector<int> res;
            for (int j = 0; j < q; ++j) {
                if (choose[j]) {
                    res.push_back(j);
                }
            }
            if (ans.size() > res.size()) {
                ans = std::move(res);
            }
        }
    }
    if (ans.size() == N) {
        cout << "-1";
    } else {
        cout << ans.size() << "\n";
        for (int t : ans) {
            cout << t + 1 << " ";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}