#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    int n, s, m;
    cin >> n >> s >> m;
    vector<pair<int, int>> vec(n);
    for (auto& [l, r] : vec) {
        cin >> l >> r;
    }

    ranges::sort(vec);
    vec.emplace_back(m, -1);

    int pre = 0;
    for (int i = 0; i <= n; ++i) {
        if (vec[i].first - pre >= s) {
            cout << "YES\n";
            return;
        }
        pre = vec[i].second;
    }
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}