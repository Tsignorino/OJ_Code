#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

static constexpr int MX = 101;
vector C(MX, vector<ll>(MX));
auto init = []() {
    for (int i = 0; i < MX; ++i) {
        C[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
        }
    }
    return 0;
}();

void solve() {
    int n;
    cin >> n;

    vector<int> vec(10);
    for (int& v : vec) {
        cin >> v;
    }

    // dfs(i, j) 表示还有 i 个空位，[j, 9] 还没有填
    vector memo(n + 1, vector<ll>(10, -1));
    auto dfs = [&](auto&& self, int i, int j) -> ll {
        if (j == 9) {
            return i >= vec[9];
        }

        ll& res = memo[i][j];
        if (res != -1) {
            return res;
        }

        int cnt = i;
        if (j == 0) {
            cnt--;
        }

        ll sum = 0;
        for (int k = vec[j]; k <= i; ++k) {
            sum = (sum + self(self, i - k, j + 1) * C[cnt][k]) % MOD;
        }
        return res = sum;
    };

    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans = (ans + dfs(dfs, i, 0)) % MOD;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}