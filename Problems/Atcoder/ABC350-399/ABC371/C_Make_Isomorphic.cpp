#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;

    int p;
    cin >> p;
    vector g1(n, vector<int>(n));
    while (p--) {
        int u, v;
        cin >> u >> v;
        u--, v--;

        g1[u][v] = g1[v][u] = 1;
    }

    int q;
    cin >> q;
    vector g2(n, vector<int>(n));
    while (q--) {
        int u, v;
        cin >> u >> v;
        u--, v--;

        g2[u][v] = g2[v][u] = 1;
    }

    vector C(n, vector<int>(n));
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            cin >> C[i][j];
            C[j][i] = C[i][j];
        }
    }

    vector<int> vec(n);
    iota(vec.begin(), vec.end(), 0);

    ll ans = LLONG_MAX;
    do {
        ll res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (g1[i][j] ^ g2[vec[i]][vec[j]]) {
                    res += C[vec[i]][vec[j]];
                }
            }
        }
        ans = min(ans, res);
    } while (ranges::next_permutation(vec).found);

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}