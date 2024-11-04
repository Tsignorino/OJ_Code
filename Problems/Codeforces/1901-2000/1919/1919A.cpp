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
