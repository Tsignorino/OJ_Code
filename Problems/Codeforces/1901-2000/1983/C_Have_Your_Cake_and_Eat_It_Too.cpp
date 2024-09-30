#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;

    vector vec(3, vector<int>(n));
    vector pre(3, vector<ll>(n + 1));
    for (int k = 0; k < 3; ++k) {
        for (int i = 0; i < n; ++i) {
            cin >> vec[k][i];
            pre[k][i + 1] = pre[k][i] + vec[k][i];
        }
    }

    vector<int> g {0, 1, 2};

    ll sum = pre[0][n];
    vector<pair<int, int>> ans(3);
    do {
        int ok = 1, id = 0;
        for (int& i : g) {
            auto& res = pre[i];
            int j = lower_bound(res.begin() + id + 1, res.end(), res[id] + (sum + 2) / 3) - res.begin();
            if (j == n + 1) {
                ok = 0;
                break;
            }
            ans[i] = pair(id + 1, j);
            id = j;
        }
        if (ok == 1) {
            for (auto& [a, b] : ans) {
                cout << a << " " << b << " ";
            }
            cout << "\n";
            return;
        }
    } while (ranges::next_permutation(g).found);

    cout << -1 << "\n";
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