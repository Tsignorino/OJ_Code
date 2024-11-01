#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    vector<int> right(n, n);
    for (int i = n - 2; i >= 0; --i) {
        if (vec[i] != vec[i + 1]) {
            right[i] = i + 1;
        } else {
            right[i] = right[i + 1];
        }
    }

    while (q--) {
        int l, r, x;
        cin >> l >> r >> x;
        l--, r--;

        if (vec[l] != x) {
            cout << l + 1 << "\n";
        } else if (right[l] <= r) {
            cout << right[l] + 1 << "\n";
        } else {
            cout << -1 << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}