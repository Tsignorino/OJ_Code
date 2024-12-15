// Date: 2024-12-15  星期天

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

const vector<int> p {1,       2,      4,       8,       16,      32, //
                     64,      128,    256,     512,     1024,    2048, //
                     4096,    8192,   16384,   32768,   65536,   131072, //
                     262144,  524288, 1048576, 2097152, 4194304, 8388608, //
                     16777216};

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int& v : a) {
        cin >> v;
    }

    const int K = 25;
    vector<ll> res(K + 1);
    for (int i = 0; i < K; ++i) {
        map<int, pair<int, ll>> memo;
        for (int& v : a) {
            auto& [c, s] = memo[((p[i] - v) % p[i] + p[i]) % p[i]];
            c++, s += v;
            auto [c1, s1] = memo[v % p[i]];
            res[i] += c1 * 1ll * v + s1;
        }
    }

    ll ans = 0;
    for (int i = 0; i < K; ++i) {
        ans += (res[i] - res[i + 1]) >> i;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}