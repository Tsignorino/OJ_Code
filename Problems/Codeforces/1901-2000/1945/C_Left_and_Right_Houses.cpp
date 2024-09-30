#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    s = ' ' + s;

    vector<int> pre(n + 2), suf(n + 2);
    int cnt1 = 0;
    for (int i = 0; i <= n; ++i) {
        cnt1 += s[i] == '0';
        pre[i] = cnt1;
    }

    int cnt2 = 0;
    for (int i = n; i > 0; --i) {
        cnt2 += s[i] == '1';
        suf[i] = cnt2;
    }

    vector<int> res;
    for (int i = 0; i <= n; ++i) {
        if (pre[i] * 2 >= i && suf[i+1] * 2 >= (n - i)) {
            res.emplace_back(i);
        }
    }

    double check = 1e9;
    int ans;
    for (int& v : res) {
        double tmp = abs(n * 1.0 / 2 - v);

        if (tmp < check) {
            ans = v;
            check = tmp;
        }
    }

    cout << ans << "\n";
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
