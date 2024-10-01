#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 998244353;

vector<int> p {1};
auto init = []() {
    for (int i = 0; i < 10; ++i) {
        p.emplace_back(p.back() * 10 % MOD);
    }
    return 0;
}();

void solve() {
    int n;
    cin >> n;

    vector<int> vec(n);
    vector<int> C(n);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];

        int res = vec[i];
        while (res) {
            res /= 10;
            C[i]++;
        }
        sum += p[C[i]];
        sum %= MOD;
    }

    vector<int> suf(n + 1);
    for (int i = n - 1; i >= 0; --i) {
        suf[i] = (suf[i + 1] + vec[i]) % MOD;
    }

    int ans = 0;
    for (int i = 0; i < n - 1; ++i) {
        sum = (sum - p[C[i]] + MOD) % MOD;
        ans += (vec[i] * 1ll * sum % MOD + suf[i + 1]) % MOD;
        ans %= MOD;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}