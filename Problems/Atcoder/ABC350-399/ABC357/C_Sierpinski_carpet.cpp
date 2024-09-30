#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;

    int p = pow(3, n);

    for (int i = 0; i < p; ++i) {
        for (int j = 0; j < p; ++j) {
            int s = 0;
            int a = i, b = j;
            for (int x = 0; x < n; ++x) {
                s = (s || a % 3 == 1 && b % 3 == 1);
                a /= 3, b /= 3;
            }
            cout << ("#."[s]);
        }
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}