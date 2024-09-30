#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;

    if (n % 2 == 0) {
        cout << -1 << "\n";
        return;
    }

    for (int i = 1; i <= (n - 1) / 2; ++i) {
        cout << i << " ";
    }
    for (int i = n; i > (n - 1) / 2; --i) {
        cout << i << " ";
    }
    cout << "\n";
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