#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    string s;
    cin >> s;

    int n = s.size();
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int k = 1; k <= n - i; ++k) {
            string t = s.substr(i, k);
            int ok = 1;
            for (int l = 0, r = t.size() - 1; l < r; ++l, --r) {
                if (t[l] != t[r]) {
                    ok = 0;
                    break;
                }
            }
            if (ok) {
                ans = max(ans, k);
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}