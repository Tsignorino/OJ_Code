#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    int n, q;
    string s1, s2;
    cin >> n >> q >> s1 >> s2;

    vector pre(n + 1, vector<int>(26));
    for (int i = 0; i < n; ++i) {
        pre[i + 1] = pre[i];
        pre[i + 1][s1[i] - 'a']++;
        pre[i + 1][s2[i] - 'a']--;
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;

        int tot = 0;
        for (int i = 0; i < 26; ++i) {
            tot += max(0, (pre[r][i] - pre[l][i]));
        }
        cout << tot << "\n";
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