#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;

    if (n == 1) {
        cout << 0 << "\n";
    } else if (n == 2) {
        cout << 2 << "\n";
    } else if (n == 3) {
        cout << 4 << "\n";
    } else if (n % 2 == 0) {
        cout << 4 << "\n";
    } else {
        cout << 6 << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}