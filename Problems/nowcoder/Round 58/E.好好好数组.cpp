#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

/*
    https://ac.nowcoder.com/acm/contest/89510/E

    手玩：
        0 1 1 1 1 1 1
        0 0 2 2 2 2 2
        0 0 0 3 3 3 3
        ……
*/

void solve() {
    int n, m;
    cin >> n >> m;

    if (n == 1) {
        cout << 2 << "\n";
    } else {
        cout << vector<int> {0, n + 1, n, 1, 0}[min(m, 4)] << "\n";
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