#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

/*
    > LCM(a, b) <= n - 1
    > b % a == 0  -->  a 是 n 的因子

    > LCM 越小  --> a 越大（不能超过 n/2）
*/

void solve() {
    int n;
    cin >> n;

    int a = 1;
    for (int i = 2; i * i <= n; ++i) { // 枚举因子
        if (n % i == 0) {
            a = n / i;
            break;
        }
    }
    cout << a << " " << n - a << "\n";
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