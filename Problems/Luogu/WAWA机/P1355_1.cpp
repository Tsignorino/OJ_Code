#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

int area(int a, int b, int x1, int y1, int x2, int y2) {
    return abs((x1 - a) * (y2 - b) - (x2 - a) * (y1 - b));
}

/*
    ! 注意数据读入
*/

void solve() {
    vector<int> x(3), y(3);
    char ch;
    for (int i = 0; i < 3; ++i) {
        cin >> ch >> x[i] >> ch >> y[i] >> ch;
    }
    int a, b;
    cin >> ch >> a >> ch >> b >> ch;

    for (int i = 0; i < 3; ++i) {
        if (a == x[i] && b == y[i]) {
            cout << 4 << "\n"; // 若点在三角形顶点上，输出 4
            return;
        }
    }

    for (int i = 0; i < 3; ++i) {
        int x1 = x[i], x2 = x[(i + 1) % 3];
        int y1 = y[i], y2 = y[(i + 1) % 3];
        if (x1 == x2 && x1 == a || (y2 - y1) * (x1 - a) == (y1 - b) * (x2 - x1)) {
            if ((b - y1) * (b - y2) + (a - x1) * (a - x2) < 0) {
                cout << 3 << "\n"; // 若点在三角形边界上（不含顶点），输出 3
                return;
            }
        }
    }

    int Ssum = 0;
    for (int i = 0; i < 3; ++i) {
        Ssum += area(a, b, x[i], y[i], x[(i + 1) % 3], y[(i + 1) % 3]);
    }
    int S = area(x[0], y[0], x[1], y[1], x[2], y[2]);
    if (Ssum > S) {
        cout << 2 << "\n"; // 若点在三角形外（不含边界），输出 2
    } else {
        cout << 1 << "\n"; // 若点在三角形内（不含边界），输出 1
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);

    solve();

    return 0;
}
