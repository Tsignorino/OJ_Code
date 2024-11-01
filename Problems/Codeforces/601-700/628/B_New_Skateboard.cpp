#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    string s;
    cin >> s;

    int n = s.size();
    ll ans = 0;
    for (int i = n - 1; i > 0; --i) {
        if (((s[i] - '0') + (s[i - 1] - '0') * 10) % 4 == 0) {
            ans += i;
        }
    }
    for (char ch : s) {
        if ((ch - '0') % 4 == 0) {
            ans++;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}