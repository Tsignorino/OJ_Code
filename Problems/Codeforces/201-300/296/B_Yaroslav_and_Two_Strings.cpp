#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    string s1, s2;
    cin >> n >> s1 >> s2;

    bool less = false, greater = false;
    ll same = 1;
    for (int i = 0; i < n; ++i) {
        char v1 = s1[i], v2 = s2[i];
        if (v1 == '?' && v2 == '?') {
            same = same * 10 % MOD;
        } else if (v1 != '?' && v2 != '?') {
            if (v1 < v2) {
                less = true;
            } else if (v1 > v2) {
                greater = true;
            }
        }
    }

    ll ans = 1;
    int cnt = count(s1.begin(), s1.end(), '?') + count(s2.begin(), s2.end(), '?');
    for (int i = 0; i < cnt; ++i) {
        ans = ans * 10 % MOD;
    }

    if (less && greater) {
        cout << ans << "\n";
        return;
    }

    ll res1 = 1, res2 = 1;
    for (int i = 0; i < n; ++i) {
        char v1 = s1[i], v2 = s2[i];
        if (v1 == '?') {
            if (v2 == '?') {
                res1 = res1 * 55 % MOD;
                res2 = res2 * 55 % MOD;
            } else {
                res1 = res1 * (v2 - '0' + 1) % MOD;
                res2 = res2 * ('9' - v2 + 1) % MOD;
            }
        } else if (v2 == '?') {
            res1 = res1 * ('9' - v1 + 1) % MOD;
            res2 = res2 * (v1 - '0' + 1) % MOD;
        }
    }

    ans -= res1 * (!greater) + res2 * (!less);
    ans += same * (!less && !greater);
    cout << (ans % MOD + MOD) % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
