#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int mod = 1e9 + 7;

// 翻转 U，改变 U 的奇偶性
void solve() {
    int n;
    string s;
    cin >> n >> s;

    cout << (ranges::count(s, 'U') & 1 ? "YES" : "NO") << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
