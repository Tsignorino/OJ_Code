#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr int mod = 1e9 + 7;

// a b l
// k x y
// l = k * a^x * b^y
void solve() {
    int a, b, l;
    cin >> a >> b >> l;

    unordered_set<int> set;
    for (int x = 0; x <= floor(log(l) / log(a)) + 1; x++) {
        for (int y = 0; y <= floor(log(l) / log(b)) + 1; y++) {
            i64 tmp = pow(a, x) * pow(b, y);
            if (tmp > l) {
                break;
            }
            if (l % tmp == 0) {
                set.insert(l / tmp);
            }
        }
    }
    cout << set.size() << "\n";
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
