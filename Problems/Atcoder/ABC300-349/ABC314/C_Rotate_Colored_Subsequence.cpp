#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    vector<vector<int>> res(m);
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;
        res[v - 1].emplace_back(i);
    }

    string ans(s);
    for (auto& tmp : res) {
        int len = tmp.size();
        for (int k = 0; k < len; ++k) {
            ans[tmp[k]] = s[tmp[(k - 1 + len) % len]];
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}