#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    int ans = 0;
    for (int i = 1; i < n - 1; ++i) {
        if (s[i - 1] == '#' && s[i] == '.' && s[i + 1] == '#') {
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