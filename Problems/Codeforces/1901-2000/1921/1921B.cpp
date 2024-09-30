#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n;
    string s, f;
    cin >> n >> s >> f;

    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; ++i) {
        int v1 = s[i] - '0', v2 = f[i] - '0';
        cnt1 += v1 == 1 && v2 == 0;
        cnt2 += v1 == 0 && v2 == 1;
    }

    cout << max(cnt1, cnt2) << "\n";
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
