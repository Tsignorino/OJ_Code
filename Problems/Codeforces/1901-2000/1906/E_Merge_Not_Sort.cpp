// Date: 2024-12-05  星期四

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> c(n * 2);
    for (int& v : c) {
        cin >> v;
    }

    vector<pair<int, int>> vec;
    for (int i = 0, j = 0; i < n * 2; i = j) {
        while (j < n * 2 && c[i] >= c[j]) {
            j++;
        }
        vec.emplace_back(i, j);
    }

    int m = vec.size();
    vector f(m + 1, vector<int>(n + 1));
    f[0][0] = 1;
    for (int i = 0; i < m; ++i) {
        f[i + 1] = f[i];
        for (int j = 0, d = vec[i].second - vec[i].first; j + d <= n; ++j) {
            if (f[i][j]) {
                f[i + 1][j + d] = 1;
            }
        }
    }
    if (f[m][n] == 0) {
        cout << -1 << "\n";
        return;
    }

    vector<pair<int, int>> a, b;
    for (int i = m, j = n; i > 0; --i) {
        if (f[i - 1][j] == 0) {
            a.emplace_back(vec[i - 1]);
            j -= vec[i - 1].second - vec[i - 1].first;
        } else {
            b.emplace_back(vec[i - 1]);
        }
    }

    for (auto& v : {a, b}) {
        for (auto& [i, j] : v | views::reverse) {
            for (int k = i; k < j; ++k) {
                cout << c[k] << " ";
            }
        }
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}