#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    string s;
    cin >> s;

    int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;
    for (const char& c : s) {
        cnt1 += c == 'U';
        cnt2 += c == 'D';
        cnt3 += c == 'L';
        cnt4 += c == 'R';
    }

    int v1 = min(cnt1, cnt2), v2 = min(cnt3, cnt4);
    if (v1 && v2) {
        cout << 2 * v1 + 2 * v2 << "\n";
        cout << string(v1, 'U') + string(v2, 'R') + string(v1, 'D') + string(v2, 'L') << "\n";
    } else if (v1 && v2 == 0) {
        cout << "2\nUD\n";
    } else if (v1 == 0 && v2) {
        cout << "2\nLR\n";
    } else {
        cout << "0\n\n";
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