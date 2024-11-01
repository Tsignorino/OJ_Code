#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1000000007;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    y--;

    for (int i = 0; i < n; ++i) {
        int v = 0;
        if (i < y) {
            v = ((y - i) % 2 == 0 ? 1 : -1);
        } else if (i < x) {
            v = 1;
        } else {
            v = ((i - x) % 2 == 0 ? -1 : 1);
        }
        cout << v << " \n"[i == n - 1];
    }
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