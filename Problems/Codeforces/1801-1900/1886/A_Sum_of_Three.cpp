#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;

    if (n < 6) { // 无法找到三个不同的正整数
        cout << "NO\n";
        return;
    }

    if (n % 3) { // 不是 3 的倍数
        cout << "YES\n";
        cout << 1 << " " << 2 << " " << n - 3 << "\n";
        return;
    }

    // 是 3 的倍数的情况
    n -= 5;
    if (n == 1 || n == 4 || n % 3 == 0) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        cout << 1 << " " << 4 << " " << n << "\n";
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
