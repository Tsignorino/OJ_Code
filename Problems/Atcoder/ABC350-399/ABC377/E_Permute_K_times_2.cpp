#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

ll qpow(ll a, ll b, int p) {
    ll res = 1;
    a = (a % p + p) % p;
    for (; b; b >>= 1, a = a * a % p) {
        if (b & 1) {
            res = a * res % p;
        }
    }
    return res;
}

void solve() {
    int n;
    ll k;
    cin >> n >> k;

    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
        v--;
    }

    vector<int> vis(n);
    for (int i = 0; i < n; ++i) {
        if (vis[i] == 1) {
            continue;
        }

        int j = i;
        vector<int> res;
        while (vis[j] == 0) {
            vis[j] = 1;
            res.emplace_back(j);
            j = vec[j];
        }

        int m = res.size();
        ll d = qpow(2, k, m);
        for (int k = 0; k < m; ++k) {
            vec[res[k]] = res[(k + d) % m];
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << vec[i] + 1 << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}