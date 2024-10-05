#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

struct Node {
    int a, p, b, q;
};

void solve() {
    int n, x;
    cin >> n >> x;

    vector<Node> vec(n);
    for (auto& [a, p, b, q] : vec) {
        cin >> a >> p >> b >> q;
        if (p * b > q * a) {
            swap(a, b), swap(p, q);
        }
    }

    auto check = [&](auto m) {
        ll ans = 0;
        for (auto& [a, p, b, q] : vec) {
            int hi = (m + a - 1) / a, lo = max(hi - lcm(a, b) / a, 0);

            ll res = numeric_limits<ll>::max();
            for (int i = lo; i <= hi; ++i) {
                res = min(res, i * 1ll * p + (max(0ll, m - i * a) + b - 1) / b * 1ll * q);
            }
            ans += res;
            if (ans > x) {
                return false;
            }
        }
        return true;
    };

    ll l = 0, r = 1e10;
    while (l + 1 < r) {
        auto mid = l + (r - l) / 2;

        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << l << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}