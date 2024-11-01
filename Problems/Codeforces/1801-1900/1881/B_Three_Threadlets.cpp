#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;

    if (a == b && a == c) { // 长度相等，无需操作
        puts("YES");
    } else {
        vector<int> vec {a, b, c};
        sort(vec.begin(), vec.end());

        int v = vec[0], x = vec[1], y = vec[2];
        // (x / v - 1) + (y / v - 1) <= 3
        if (x % v == 0 && y % v == 0 && x / v + y / v <= 5) {
            puts("YES");
        } else {
            puts("NO");
        }
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