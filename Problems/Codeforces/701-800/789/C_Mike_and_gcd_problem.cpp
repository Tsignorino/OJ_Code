#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

/*
    考虑 gcd(x, y) 和 gcd(x-y, x+y)

    gcd(x-y, x+y) = gcd(x-y, 2x) = gcd(x-y, 2y)  ==>  gcd(x-y, x+y) 是 2x 和 2y 的因子，也是 2gcd(x, y) 的因子
    gcd(x, y) 能被 x-y 和 x+y 整除  ==>  gcd(x, y) 是 gcd(x-y, x+y) 的因子
==> gcd(x-y, x+y) 只能是 gcd(x, y) 或者 2gcd(x, y)

    如需操作，操作后数组一定全部为偶数
*/

void solve() {
    int n;
    cin >> n;
    vector<int> vec(n);
    int g = 0;
    for (int& v : vec) {
        cin >> v;
        g = gcd(g, v);
    }

    int cnt = 0;
    if (g == 1) {
        for (int i = 0; i < n; ++i) {
            if (vec[i] % 2 == 1) {
                if (i + 1 == n || vec[i + 1] % 2 == 0) {
                    cnt += 2;
                } else {
                    vec[i + 1]++; // 变成偶数
                    cnt++;
                }
            }
        }
    }
    cout << "YES\n" << cnt << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}