#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int a, b;
    cin >> a >> b;

    if ((a + b) & 1) {
        cout << "Alice\n";
    } else {
        cout << "Bob\n";
    }
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
