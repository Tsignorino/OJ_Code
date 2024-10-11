#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, k;
    cin >> n >> k;

    set<int> s;
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;
        s.emplace(v);
    }

    for (int i = 1; i <= k; ++i) {
        if (!s.contains(i)) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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