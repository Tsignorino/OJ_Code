#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    string s;
    cin >> s;

    vector<ll> tot(26), cnt(26);
    ll ans = 0;
    for (int i = 0; i < s.size(); ++i) {
        int v = s[i] - 'A';
        if (cnt[v]) {
            ans += (i - 1) * cnt[v] - tot[v];
        }
        tot[v] += i;
        cnt[v]++;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}