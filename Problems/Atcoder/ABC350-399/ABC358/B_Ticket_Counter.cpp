#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, t;
    cin >> n >> t;

    int cur = 0;
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;

        if (cur < v) {
            cur = v;
        }
        cur += t;

        cout << cur << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}