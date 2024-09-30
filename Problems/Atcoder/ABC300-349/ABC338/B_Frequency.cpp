#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    string s;
    cin >> s;

    vector<int> C(26);
    char ans = s[0];
    int cnt = 0;
    for (char ch : s) {
        int v = ++C[ch - 'a'];
        if (v > cnt) {
            cnt = v;
            ans = ch;
        } else if (v == cnt) {
            ans = min(ans, ch);
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