#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;

    vector<int> cnt(n);
    for (int i = 0; i < 3 * n; ++i) {
        int v;
        cin >> v;
        if (++cnt[v - 1] == 2) {
            cout << v << " ";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}