#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

int ask(int x, int y) {
    cout << format("? {} {}", x, y) << endl;
    int res;
    cin >> res;
    return res;
}

void solve() {
    int n, m;
    cin >> n >> m;

    int a = ask(1, 1);
    int b = ask(n, 1);
    int c = ask(1, m);

    int x1 = (a - b + n + 1) / 2, y1 = (a + b - n + 1) / 2 + 1;
    int x2 = (a + c - m + 1) / 2 + 1, y2 = (a - c + m + 1) / 2;

    if (x1 >= 1 && x1 <= n && y1 >= 1 && y1 <= m && ask(x1, y1) == 0) {
        cout << format("! {} {}", x1, y1) << endl;
    } else {
        cout << format("! {} {}", x2, y2) << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}