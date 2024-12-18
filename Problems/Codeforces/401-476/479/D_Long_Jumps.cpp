// Date: 2024-12-18  星期三

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

void solve() {
    int n, l, x, y;
    cin >> n >> l >> x >> y;

    vector<int> a(n);
    for (int& v : a) {
        cin >> v;
    }

    set<int> s(a.begin(), a.end());
    int ok1 = s.contains(x), ok2 = s.contains(y);
    for (int& v : a) {
        if (s.contains(v + x)) {
            ok1 = 1;
        }
        if (s.contains(v + y)) {
            ok2 = 1;
        }
    }

    if (ok1 && ok2) {
        cout << 0 << "\n";
    } else if (ok1 && !ok2) {
        cout << 1 << "\n" << y << "\n";
    } else if (!ok1 && ok2) {
        cout << 1 << "\n" << x << "\n";
    } else {
        // 原来的差值有 y-x 或 x+y
        for (int i = 0; i < n - 1; ++i) {
            if (s.contains(a[i] + x + y)) {
                cout << 1 << "\n" << a[i] + x << "\n";
                return;
            }
            if (s.contains(a[i] + y - x)) {
                if (a[i] - x >= 0) {
                    cout << 1 << "\n" << a[i] - x << "\n";
                    return;
                }
                if (a[i] + y <= l) {
                    cout << 1 << "\n" << a[i] + y << "\n";
                    return;
                }
            }
        }
        cout << 2 << "\n";
        cout << x << " " << y << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

/*
case 1:
3 250 185 230
0 185 250

1
230

case 2:
4 250 185 230
0 20 185 250

0

case 3:
2 300 185 230
0 300

2
185 230

case 4:
4 300 4 5
0 6 7 300

1
11

case 5:
2 100 30 70
0 100

1
30

case 6:
4 300 4 5
0 298 299 300

1
294

case 7:
4 10 3 5
0 1 9 10

1
4

case 8:
18 187 27 157
0 17 18 31 36 37 40 53 73 86 96 107 119 150 167 181 184 187

1
27

case 9:
112 1867 1261 1606
0 7 17 43 67 70 87 112 129 141 148 162 179 180 189 202 211 220 231 247 250 277 308 311 327 376 400 406 409 417 418 444 480 512 514 515 518 547 572 575 578 587 612 617 654 684 701 742 757 761 788 821
825 835 841 843 850 858 869 872 881 936 939 969 970 971 997 1026 1040 1045 1068 1070 1073 1076 1095 1110 1115 1154 1166 1178 1179 1203 1204 1225 1237 1241 1246 1275 1302 1305 1311 1312 1315 1338 1340
1419 1428 1560 1561 1576 1591 1594 1618 1643 1658 1660 1664 1689 1803 1822 1835 1867

1
1808
*/