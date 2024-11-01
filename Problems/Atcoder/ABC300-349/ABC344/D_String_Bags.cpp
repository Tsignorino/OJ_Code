#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    string t;
    cin >> t;

    int m = t.size();
    vector<int> f(m + 1, INT_MAX / 2);
    f[0] = 0;

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        vector<int> g(f);

        int q;
        cin >> q;
        for (int j = 0; j < q; ++j) {
            string s;
            cin >> s;
            for (int k = 0; k < m; k += 1) {
                int v = k + s.size();
                if (s == t.substr(k, s.size())) {
                    g[v] = min(g[v], f[k] + 1);
                }
            }
        }

        f = std::move(g);
    }

    cout << (f.back() == INT_MAX / 2 ? -1 : f.back()) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}