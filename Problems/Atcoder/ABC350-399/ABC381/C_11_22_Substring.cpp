// Date: 2024-11-23  星期六

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '/') {
            int p = i - 1, q = i + 1;
            while (p >= 0 && s[p] == '1') {
                p--;
            }
            while (q < n && s[q] == '2') {
                q++;
            }
            ans = max(ans, min(i - p - 1, q - i - 1) * 2 + 1);
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