#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

void solve() {
    ll n, a, b;
    cin >> n >> a >> b;

    if (b <= a) { // 全 a
        cout << a * n << "\n";
    } else if (b - a >= n) { // 全 b
        cout << (2 * b - n + 1) * n / 2 << "\n";
    } else { // a, b 都有
        cout << (a + 1 + b) * (b - a) / 2 + a * (n - b + a) << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
