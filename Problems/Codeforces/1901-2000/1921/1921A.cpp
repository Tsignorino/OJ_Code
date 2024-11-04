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
