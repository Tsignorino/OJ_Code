#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int x, d;
    cin >> x >> d;

    vector<ll> vec;
    for (ll v = 1; x > 0; v += d) {
        int len = 32 - __builtin_clz(x);
        if ((1 << len) - 1 > x) {
            len--;
        }
        x -= (1 << len) - 1;
        while (len-- > 0) {
            vec.emplace_back(v);
        }
    }

    cout << vec.size() << "\n";
    for (ll& v : vec) {
        cout << v << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
