#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> vec(n);
    map<int, pair<int, int>> mp;
    for (int i = 0; i < n; ++i) {
        int m;
        cin >> m;

        vec[i].resize(m);
        int sum = 0;
        for (int& v : vec[i]) {
            cin >> v;
            sum += v;
        }
        for (int j = 0; j < m; ++j) {
            int v = sum - vec[i][j];
            if (mp.find(v) != mp.end()) {
                if (mp[v].first != i) {
                    cout << "YES\n";
                    cout << i + 1 << " " << j + 1 << "\n";
                    cout << mp[v].first + 1 << " " << mp[v].second + 1 << "\n";
                    return;
                }
            } else {
                mp[v] = {i, j};
            }
            
        }
    }
    cout << "NO\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();

    return 0;
}
