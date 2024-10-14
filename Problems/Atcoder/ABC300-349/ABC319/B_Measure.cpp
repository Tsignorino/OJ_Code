#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;

    for (int i = 0; i <= n; ++i) {
        int ok = 1;
        for (int j = 1; j <= 9; ++j) {
            if (n % j == 0 && i % (n / j) == 0) {
                ok = 0;
                cout << j;
                break;
            }
        }
        if (ok) {
            cout << '-';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}