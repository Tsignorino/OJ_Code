#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int a, b;
    cin >> a >> b;

    if (a == 1 && b == 0) {
        cout << "Yes\n";
    } else if (a == 0 && b == 1) {
        cout << "No\n";
    } else {
        cout << "Invalid\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}