#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    int len = __lg(n);
    vector<vector<int>> st(n, vector<int>(len + 1));
    auto init = [&]() -> int {
        for (int i = 0; i < n; ++i) {
            st[i][0] = vec[i];
        }
        for (int i = 1; i <= len; ++i) {
            for (int j = 0; j + (1 << i) - 1 < n; ++j) {
                st[j][i] = gcd(st[j][i - 1], st[j + (1 << (i - 1))][i - 1]);
            }
        }
        return 0;
    }();

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;

        int s = __lg(r - l + 1);
        cout << gcd(st[l][s], st[r - (1 << s) + 1][s]) << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
