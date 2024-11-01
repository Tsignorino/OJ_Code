#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    string s;
    cin >> s;

    int n = s.size();

    vector memo(n, vector<int>(n, -1));
    auto dfs = [&](auto&& dfs, int x, int y) -> int {
        if (x >= y) {
            return 0;
        }

        int& res = memo[x][y];
        if (res != -1) {
            return res;
        }

        if (s[x] == s[y]) {
            return res = dfs(dfs, x + 1, y - 1);
        }
        return res = min(dfs(dfs, x + 1, y), dfs(dfs, x, y - 1)) + 1;
    };

    cout << dfs(dfs, 0, n - 1) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}