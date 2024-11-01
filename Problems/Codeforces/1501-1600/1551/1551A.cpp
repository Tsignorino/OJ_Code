#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    int c1, c2;
    c1 = c2 = n / 3;
    if (n % 3 == 1) {
        c1++;
    } else if (n % 3 == 2) {
        c2++;
    }

    cout << c1 << " " << c2 << "\n";
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
