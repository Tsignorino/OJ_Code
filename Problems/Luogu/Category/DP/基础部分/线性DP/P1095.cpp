#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/*
    守望者的逃离
*/

void solve() {
    int m, s, t;
    cin >> m >> s >> t;

    // 跑步 17m/s   闪烁 60m/s   消耗 10点/s   恢复 4点/s
    vector<int> f(t + 1);
    for (int i = 1; i <= t; ++i) {
        if (m >= 10) {
            f[i] = f[i - 1] + 60;
            m -= 10;
        } else {
            f[i] = f[i - 1];
            m += 4;
        }
    }

    for (int i = 1; i <= t; ++i) {
        if (f[i] < f[i - 1] + 17) {
            f[i] = f[i - 1] + 17;
        }
        if (f[i] >= s) {
            cout << "Yes\n" << i << "\n";
            return;
        }
    }
    cout << "No\n" << f[t] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}