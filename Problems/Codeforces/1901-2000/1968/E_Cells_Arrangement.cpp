#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;

    cout << format("{} {}\n", 1, 1);
    cout << format("{} {}\n", 1, 2);
    for (int i = 3; i <= n; ++i) {
        cout << format("{} {}\n", i, i);
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