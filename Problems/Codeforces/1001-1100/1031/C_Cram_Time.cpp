#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;

    int l = -1, r = 1e5;
    while (l + 1 < r) {
        int mid = l + (r - l) / 2;
        (mid * 1ll * (mid + 1) / 2 > n + m ? r : l) = mid;
    }

    vector<int> a, b;
    for (int i = l; i > 0; --i) {
        if (n > m) {
            a.emplace_back(i);
            n -= i;
        } else {
            b.emplace_back(i);
            m -= i;
        }
    }

    int s1 = a.size(), s2 = b.size();
    cout << s1 << "\n";
    for (int i = 0; i < s1; ++i) {
        cout << a[i] << " \n"[i == s1 - 1];
    }
    cout << s2 << "\n";
    for (int i = 0; i < s2; ++i) {
        cout << b[i] << " \n"[i == s2 - 1];
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();

    return 0;
}
