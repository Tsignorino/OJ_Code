#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

void solve() {
    int a, b;
    cin >> a >> b;
    // cout << (a == b ? -1 : 6 - a - b) << "\n";
    cout << (a == b ? -1 : a ^ b) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);

    solve();

    return 0;
}
