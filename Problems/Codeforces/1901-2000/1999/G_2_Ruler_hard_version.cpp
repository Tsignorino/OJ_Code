#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

static constexpr int MOD = 1e9 + 7;

int Ask(int a, int b) {
    cout << format("? {} {}", a, b) << endl;
    int val;
    cin >> val;
    return val;
}
void Ans(int a) {
    cout << format("! {}", a) << endl;
}

void solve() {
    int l = 1, r = 999;
    while (l + 1 < r) {
        int x = l + (r - l) / 3, y = l + (r - l) * 2 / 3;
        int val = Ask(x, y);
        if (val == x * y) {
            l = y;
        } else if (val == x * (y + 1)) {
            l = x, r = y;
        } else {
            r = x;
        }
    }
    Ans(r);
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