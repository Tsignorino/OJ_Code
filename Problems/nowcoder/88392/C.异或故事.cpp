#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

/*
    https://ac.nowcoder.com/acm/contest/88392/C
*/

void solve() {
    int n;
    cin >> n;

    if (n == 1) {
        cout << format("{} {}", 2, 3) << "\n";
    } else if (n == 1e9) {
        cout << format("{} {}", 512, 999999488) << "\n";
    } else {
        cout << format("{} {}", 1, n ^ 1) << "\n";
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