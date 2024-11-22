#include <bits/stdc++.h>

using namespace std;
using ll = long long;

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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
