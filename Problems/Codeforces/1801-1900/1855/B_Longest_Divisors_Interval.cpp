#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define mod 1e9 + 7

void solve() {
    // 找到最长区间，使得区间内的数能够被 n 整除
    /*
        如果 n 不是 x 的倍数，那么 ans < x，否则，ans >= x
        （可以假定 l = 1 判断）

        ==> 区间 [l, r] 里面的数都是 n 的因子，
            ==> 区间 [l, r] 里面必然有 r-l+1 的倍数
            ==> x = r - l + 1 必然是 n 的因子
        即，1 ~ r-l+1 里面的数都是 n 的因子
    */
    ll n;
    cin >> n;

    int i = 2;
    while (n % i == 0) {
        i++;
    }

    cout << i - 1 << "\n";
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
