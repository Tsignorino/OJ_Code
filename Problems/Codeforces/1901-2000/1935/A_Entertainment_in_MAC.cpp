#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    int m = s.size();
    for (int i = 0; i < m / 2; ++i) {
        if (s[i] < s[m - i - 1]) {
            break;
        }
        if (s[i] > s[m - i - 1]) {
            string ss(s);
            reverse(ss.begin(), ss.end());
            cout << ss << s << "\n";
            return;
        }
    }

    cout << s << "\n";
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
