#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    int ans = 0;
    string t;
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == '1') {
            t += string(i + 1, 'A');
            t += string(i, 'B');
            ans += 2 * i + 1;
        }
    }
    cout << ans << "\n" << t << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
