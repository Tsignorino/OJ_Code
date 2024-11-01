#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

// 乘法快速幂，未取模
ll qpow(ll a, ll b) {
    ll res = 1;
    for (; b; b >>= 1) {
        if (b & 1) {
            res = res * a;
        }
        a = a * a;
    }
    return res;
}

void solve() {
    ll n;
    cin >> n;

    if (n == 1) {
        cout << 1 << "\n";
        return;
    }
    for (int i = 2; i < 20; ++i) {
        ll res = qpow(i, i);
        if (res == n) {
            cout << i << "\n";
            return;
        } else if (res > n) {
            break;
        }
    }
    cout << -1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}