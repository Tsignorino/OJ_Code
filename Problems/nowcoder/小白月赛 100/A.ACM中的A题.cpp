#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    ll a, b, c;
    cin >> a >> b >> c;

    auto f = [&](ll a, ll b, ll c) {
        vector<ll> res {a, b, c};
        ranges::sort(res);
        return res[0] + res[1] > res[2];
    };

    cout << ((f(a * 2, b, c) | f(a, b * 2, c) | f(a, b, c * 2)) ? "Yes" : "No") << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}