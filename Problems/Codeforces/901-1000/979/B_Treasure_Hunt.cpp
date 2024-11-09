#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    string a, b, c;
    cin >> n >> a >> b >> c;

    auto func = [&](const string& s) {
        int m = s.size();
        vector<int> cnt(26 * 2 + 1);
        for (char ch : s) {
            if (isupper(ch)) {
                cnt[ch - 'A']++;
            } else {
                cnt[ch - 'a' + 26]++;
            }
        }
        int mx = ranges::max(cnt);
        return mx == m && n == 1 && m != 1 ? mx - 1 : min(mx + n, m);
    };

    int v0 = func(a), v1 = func(b), v2 = func(c);
    if (v0 > v1 && v0 > v2) {
        cout << "Kuro\n";
    } else if (v1 > v0 && v1 > v2) {
        cout << "Shiro\n";
    } else if (v2 > v0 && v2 > v1) {
        cout << "Katie\n";
    } else {
        cout << "Draw\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}