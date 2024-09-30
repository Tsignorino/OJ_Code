#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    ll sum = accumulate(vec.begin(), vec.end(), 0ll);

    vector<int> preXor(n + 1);
    for (int i = 0; i < n; i++) {
        preXor[i + 1] = preXor[i] ^ vec[i];
    }

    ll res = 0;
    for (int k = 0; k < 31; k++) {
        ll cnt = 0;
        for (int i = 0; i <= n; i++) {
            cnt += preXor[i] >> k & 1;
        }
        res += 1ll * cnt * (n + 1 - cnt) * (1 << k);
    }

    cout << res - sum << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}