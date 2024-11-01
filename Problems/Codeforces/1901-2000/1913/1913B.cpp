#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    string s;
    cin >> s;

    int n = s.size();
    int cnt0 = 0;
    for (int i = 0; i < n; ++i) {
        cnt0 += s[i] == '0';
    }
    int cnt1 = n - cnt0;

    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            if (cnt1 == 0) {
                break;
            } else {
                cnt1--;
            }
        }

        if (s[i] == '1') {
            if (cnt0 == 0) {
                break;
            } else {
                cnt0--;
            }
        }
    }

    cout << cnt1 + cnt0 << "\n";
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
