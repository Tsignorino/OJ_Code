#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;

    vector<int> f(32);
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;

        int mx = 0;
        for (int i = 31; i >= 0; --i) {
            if (v >> i & 1) {
                mx = max(mx, f[i]);
            }
        }
        for (int i = 31; i >= 0; --i) {
            if (v >> i & 1) {
                f[i] = mx + 1;
            }
        }
    }
    cout << ranges::max(f) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}