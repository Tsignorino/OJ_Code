#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    // 分解成两个偶数之和
    if (n % 2 == 0 && n > 2) {
        puts("YES");
    } else {
        puts("NO");
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();

    return 0;
}
