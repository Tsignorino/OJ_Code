#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int mod = 1e9 + 7;

void solve() {
    ll n, k, a, b;
    cin >> n >> k >> a >> b;

    map<ll, double> mp;
    function<double(ll)> dfs = [&](ll num) -> double {
        if (num == 0) {
            return 0;
        }

        if (mp.find(num) != mp.end()) {
            return mp[num];
        }

        double res = dfs(num / k) + a;
        res = min(res, (dfs(num / 2) + dfs(num / 3) + dfs(num / 4) + dfs(num / 5) + dfs(num / 6) + b * 6) / 5);
        return mp[num] = res;
    };

    cout << dfs(n) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
