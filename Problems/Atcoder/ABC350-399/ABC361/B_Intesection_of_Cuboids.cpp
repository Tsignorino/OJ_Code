#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

void solve() {
    int a1, b1, c1, d1, e1, f1;
    int a2, b2, c2, d2, e2, f2;
    cin >> a1 >> b1 >> c1 >> d1 >> e1 >> f1;
    cin >> a2 >> b2 >> c2 >> d2 >> e2 >> f2;

    int ok = 1;
    if (a2 >= d1 || d2 <= a1 || b2 >= e1 || e2 <= b1 || c2 >= f1 || f2 <= c1) {
        ok = 0;
    }
    cout << (ok ? "Yes" : "No") << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
