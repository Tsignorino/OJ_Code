#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> vec(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char ch;
            cin >> ch;
            if (ch == 'o') {
                vec[i] |= 1 << j;
            }
        }
    }

    auto dfs = [&](auto&& self, int i, int cur, int cnt) -> int {
        if (i == n) {
            return cur == (1 << m) - 1 ? cnt : n;
        }
        return min(self(self, i + 1, cur | vec[i], cnt + 1), self(self, i + 1, cur, cnt));
    };
    cout << dfs(dfs, 0, 0, 0) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}