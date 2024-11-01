#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define mod 1e9 + 7

void solve() {
    int a, b, c;
    cin >> a >> b >> c;

    // 奇偶校验：去掉两个不同的数，补上第三个数（相当于进行异或）
    cout << (abs(b - c) % 2 == 0) << " " << (abs(a - c) % 2 == 0) << " " << (abs(a - b) % 2 == 0) << "\n";
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
