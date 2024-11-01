#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    string s;
    cin >> s;

    int cnt[26] {};
    for (auto& c : s) {
        cnt[c - 'a']++;
    }

    ll ans = 0;
    for (int i = 0; i < 26; i++) {
        ans += 1LL * cnt[i] * (cnt[i] - 1) / 2;
    }

    int n = s.size();
    ans = 1LL * n * (n - 1) / 2 - ans;
    if (ans < 1LL * n * (n - 1) / 2) {
        ans++;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
