#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<ll> ans(n);
    ans[n - 1] = 1;

    vector<int> nxt(26, n);
    nxt[s[n - 1] - 'a'] = n - 1;

    for (int i = n - 2; i >= 0; --i) {
        ans[i] = ans[i + 1] + (nxt[s[i] - 'a'] - i);
        nxt[s[i] - 'a'] = i;
    }
    cout << ans[0] << "\n";
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
