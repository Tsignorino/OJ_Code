#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<ll> ans(n);
    vector<int> nxt(26, n);
    ans[n - 1] = 1;
    nxt[s[n - 1] - 'a'] = n - 1;

    for (int i = n - 2; i >= 0; --i) {
        ans[i] = ans[i + 1] + (nxt[s[i] - 'a'] - i);
        nxt[s[i] - 'a'] = i;
    }
    cout << ans[0] << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int count;
    cin >> count;
    while (count--) {
        solve();
    }

    return 0;
}
