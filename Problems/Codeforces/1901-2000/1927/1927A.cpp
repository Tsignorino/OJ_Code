#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define mod 1e9 + 7

void solve() {
    int n;
    string s;
    cin >> n >> s;

    int l = 0, r = n - 1;
    while (l < r) {
        if (s[l] != 'B') {
            l++;
        } else if (s[r] != 'B') {
            r--;
        } else {
            break;
        }
    }

    cout << r - l + 1 << "\n";
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
