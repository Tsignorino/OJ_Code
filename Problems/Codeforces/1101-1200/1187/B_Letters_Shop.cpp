#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, q;
    string s;
    cin >> n >> s >> q;

    map<char, vector<int>> memo;
    for (int i = 0; i < n; ++i) {
        memo[s[i]].emplace_back(i);
    }

    while (q--) {
        string t;
        cin >> t;

        map<char, int> mp;
        for (char ch : t) {
            mp[ch]++;
        }

        int ans = 0;
        for (auto& [v, c] : mp) {
            ans = max(ans, memo[v][c - 1]);
        }
        cout << ans + 1 << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}