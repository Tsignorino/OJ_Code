#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }
    for (int i = 1; i < n; ++i) {
        if (vec[i] > vec[0]) {
            cout << i + 1 << "\n";
            return;
        }
    }
    cout << -1 << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(20);

    solve();

    return 0;
}
