// Date: 2024-11-30  星期六

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

    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == '@' && k) {
            s[i] = '.';
            k--;
        }
    }

    cout << s << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}