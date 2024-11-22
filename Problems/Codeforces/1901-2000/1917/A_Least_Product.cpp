#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    int sign = 1;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];

        if (a[i] < 0) {
            sign *= -1;
        }
        if (a[i] == 0) {
            sign = 0;
        }
    }

    if (sign > 0) {
        cout << 1 << "\n";
        cout << 1 << " " << 0 << "\n";
    } else {
        cout << 0 << "\n";
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