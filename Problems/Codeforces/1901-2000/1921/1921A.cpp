#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    vector<int> x(4), y(4);
    for (int i = 0; i < 4; ++i) {
        cin >> x[i] >> y[i];
    }

    int dx = ranges::max(x) - ranges::min(x);
    cout << dx * dx << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int count;
    cin >> count;
    while (count--) {
        solve();
    }

    return 0;
}
