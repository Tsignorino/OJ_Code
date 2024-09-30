#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

void solve() {
    string s;
    cin >> s;

    int n = s.size();
    vector<int> nxt(n + 1), cnt(n + 1);
    cnt[0] = 0, cnt[1] = 1;
    int j = 0;
    for (int i = 1; i < n; ++i) {
        while (j && s[i] != s[j]) {
            j = nxt[j];
        }
        if (s[i] == s[j]) {
            j++;
        }
        nxt[i + 1] = j;
        cnt[i + 1] = cnt[j] + 1;
    }

    ll ans = 1;
    j = 0;
    for (int i = 1; i < n; ++i) {
        while (j && s[i] != s[j]) {
            j = nxt[j];
        }
        if (s[i] == s[j]) {
            j++;
        }
        while (j * 2 > i + 1) {
            j = nxt[j];
        }
        ans = ans * 1ll * (cnt[j] + 1) % MOD;
    }
    cout << ans << "\n";
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