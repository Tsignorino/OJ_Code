#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;
        if (v % k == 0) {
            cout << v / k << " ";
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
