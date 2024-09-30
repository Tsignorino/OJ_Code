#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;

    for (int i = n; i >= 0; --i) {
        int val;
        cin >> val;

        //* 一元 n 次多项式，首项非 0
        if (val) { // 判零
            if (i != n && val > 0) { // 正数、非首项
                cout << '+';
            }

            if (abs(val) > 1 || i == 0) { // 非 ±1 or 末项
                cout << val;
            }

            if (val == -1 && i) { // -1、非末项
                cout << '-';
            }

            // 幂次
            if (i > 1) {
                cout << "x^" << i;
            }
            if (i == 1) {
                cout << 'x';
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);

    solve();

    return 0;
}
