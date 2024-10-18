#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;

    vector<ll> b(64);
    ll or_ = 0;
    for (int i = 0; i < n; ++i) {
        ll v;
        cin >> v;

        or_ |= v;
        for (int i = b.size() - 1; i >= 0; --i) {
            if ((v >> i & 1) == 0) {
                continue;
            }
            if (b[i] == 0) {
                b[i] = v;
            }
            v ^= b[i];
        }
    }

    ll res = 0;
    for (int i = b.size() - 1; i >= 0; --i) {
        if ((res ^ b[i]) > res) {
            res ^= b[i];
        }
    }
    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}