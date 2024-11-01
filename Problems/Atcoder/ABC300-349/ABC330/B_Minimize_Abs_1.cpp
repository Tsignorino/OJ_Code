#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, l, r;
    cin >> n >> l >> r;

    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;

        if (val >= r) {
            cout << r << " ";
        } else if (val <= l) {
            cout << l << " ";
        } else {
            cout << val << " ";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}