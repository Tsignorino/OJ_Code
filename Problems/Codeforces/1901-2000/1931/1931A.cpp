#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define mod 1e9 + 7

void solve() {
    int n;
    cin >> n;

    string s("aaa");
    int cnt = n - 3;
    for (int i = 0; i < cnt; ++i) {
        if (s[2] < 'z') {
            s[2]++;
        } else if (s[1] < 'z') {
            s[1]++;
        } else {
            s[0]++;
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
