#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;

    cout << (abs(a - b) > n - a - b ? "Yes" : "No") << "\n"; // max(a, b) * 2 > n
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}