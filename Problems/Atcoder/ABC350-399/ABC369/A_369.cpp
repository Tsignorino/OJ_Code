#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int a, b;
    cin >> a >> b;

    if (a == b) {
        cout << 1 << "\n";
    } else if (abs(a - b) % 2) {
        cout << 2 << "\n";
    } else {
        cout << 3 << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}