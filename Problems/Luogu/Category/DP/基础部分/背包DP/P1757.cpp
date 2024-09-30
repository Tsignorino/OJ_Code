#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Node {
    int a, b, c;
};

void solve() {
    int m, n;
    cin >> m >> n;
    vector<Node> vec(n);
    map<int, vector<pair<int, int>>> map;
    for (auto& [a, b, c] : vec) {
        cin >> a >> b >> c;
        map[c].emplace_back(pair(a, b));
    }

    vector<int> dp(m + 1);
    for (auto& [x, res] : map) {
        for (int j = m; j >= 0; --j) {
            for (auto& p : res) {
                if (j >= p.first) {
                    dp[j] = max(dp[j], dp[j - p.first] + p.second);
                }
            }
        }
    }
    cout << dp[m] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}