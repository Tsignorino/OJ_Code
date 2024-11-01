#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, g, m;
    cin >> n >> g >> m;

    int v1 = 0, v2 = 0;
    while (n--) {
        if (v1 == g) {
            v1 = 0;
        } else if (v2 == 0) {
            v2 = m;
        } else {
            int d = min(g - v1, v2);
            v1 += d;
            v2 -= d;
        }
    }
    cout << v1 << " " << v2 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}