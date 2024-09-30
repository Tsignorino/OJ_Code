#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/**
 * * 要求路径成环状（除原点外不重复），最后返回原点，那么向左或向上 和 向右或向下 走的路径长度是一样的
 * * 注意分类讨论
 */
void solve() {
    string s;
    cin >> s;

    int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;
    for (const char& c : s) {
        cnt1 += c == 'U';
        cnt2 += c == 'D';
        cnt3 += c == 'L';
        cnt4 += c == 'R';
    }

    int v1 = min(cnt1, cnt2), v2 = min(cnt3, cnt4);
    if (v1 && v2) {
        cout << 2 * v1 + 2 * v2 << "\n";
        cout << string(v1, 'U') + string(v2, 'R') + string(v1, 'D') + string(v2, 'L') << "\n";
    } else if (v1 && v2 == 0) {
        cout << "2\nUD\n";
    } else if (v1 == 0 && v2) {
        cout << "2\nLR\n";
    } else {
        cout << "0\n\n";
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
