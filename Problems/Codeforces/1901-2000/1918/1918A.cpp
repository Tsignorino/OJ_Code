#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// 一排中最多只能放置 m/2 块水平砖块。答案不会超过 m/2；
// 另一方面，如果将长度为 2 的水平砖块排成一行，并且当 m 为奇数时，
// 最后一块砖块的长度为 3，则每行中将恰好有 m/2 个水平砖块砖，实现最大稳定性。
void solve() {
    int n, m;
    cin >> n >> m;

    cout << m / 2 * n << "\n";
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
