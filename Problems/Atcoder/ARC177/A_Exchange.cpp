#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

void solve() {
    vector<int> vec(6);
    for (int& v : vec) {
        cin >> v;
    }
    ranges::reverse(vec);

    int n;
    cin >> n;

    vector<int> fee {500, 100, 50, 10, 5, 1};
    bool flag = true;
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;

        if (flag == false) {
            continue;
        }

        for (int i = 0; i < 6; ++i) {
            if (v >= fee[i]) {
                int cnt = min(vec[i], v / fee[i]);
                vec[i] -= cnt;
                v -= cnt * fee[i];
            }
        }
        if (v) {
            flag = false;
        }
    }

    cout << (flag ? "Yes" : "No") << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(20);

    solve();

    return 0;
}
