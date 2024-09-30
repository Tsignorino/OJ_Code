#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(1001), b(1001);
    vector<vector<int>> c(1001, vector<int>(1001));
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char k;
            cin >> k;
            if (k == '*') {
                cnt++;
                a[i]++;
                b[j]++;
                c[i][j]++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (cnt - a[i] - b[j] + c[i][j] == 0) {
                cout << "YES\n" << i + 1 << " " << j + 1;
                return;
            }
        }
    }

    cout << "NO";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();

    return 0;
}
