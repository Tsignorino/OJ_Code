#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    int p = 0, q = 0;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        int ok = 0;
        while (s[i] == '1') {
            i++;
            ok = 1;
        }
        if (ok) {
            cnt++;
            if (cnt == k - 1) {
                p = i;
            } else if (cnt == k) {
                q = i;
            }
        }
    }

    ranges::reverse(s.begin() + p, s.begin() + q);
    cout << s << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}