#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;

    // for (int i = 0; i < n; i++) {
    //     string s = "";
    //     for (int j = 0; j < n; j++) {
    //         s += ((i + j) % 2 == 0 ? "##" : "..");
    //     }
    //     cout << s << '\n';
    //     cout << s << '\n';
    // }

    for (int i = 0; i < 2 * n; ++i) {
        for (int j = 0; j < 2 * n; ++j) {
            cout << "#."[(i >> 1) ^ (j >> 1) & 1];
        }
        cout << "\n";
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