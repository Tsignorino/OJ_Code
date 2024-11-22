#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int mod = 1e9 + 7;

void solve() {
    int a, b;
    cin >> a >> b;

    if (b % a == 0) {
        cout << b * 1LL * b / a << "\n";
        return;
    }
    cout << b * 1LL * a / gcd(a, b) << "\n";
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
