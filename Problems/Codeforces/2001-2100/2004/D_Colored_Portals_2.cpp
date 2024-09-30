#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

/*
    数字比较  171ms
*/

void solve() {
    int n, q;
    cin >> n >> q;

    map<char, int> ci {
        {'B', 1},
        {'R', 2},
        {'G', 4},
        {'Y', 8}
    };

    vector<int> vec(n);
    map<int, vector<int>> mp;
    for (int i = 0; i < n; ++i) {
        char ch1, ch2;
        cin >> ch1 >> ch2;

        vec[i] = ci[ch1] + ci[ch2];
        mp[vec[i]].emplace_back(i);
    }

    while (q--) {
        int u, v;
        cin >> u >> v;
        u--, v--;

        if (u > v) {
            swap(u, v);
        }

        if (vec[u] & vec[v]) {
            cout << v - u << "\n";
            continue;
        }

        int ans = INT_MAX;
        int ok = 1;
        for (int val : {0b1100, 0b1010, 0b1001, 0b0110, 0b0101, 0b0011}) {
            if (val == vec[u] || val == vec[v]) {
                continue;
            }

            auto& res = mp[val];

            auto iter1 = ranges::upper_bound(res, u), iter2 = ranges::lower_bound(res, v);
            if (iter1 != res.end()) {
                if (*iter1 <= v) {
                    ok = 0;
                    cout << v - u << "\n";
                    break;
                } else {
                    ans = min(ans, 2 * (*iter1) - v - u);
                }
            }
            if (iter2 != res.begin()) {
                if (*prev(iter2) >= u) {
                    ok = 0;
                    cout << v - u << "\n";
                    break;
                } else {
                    ans = min(ans, u + v - 2 * (*prev(iter2)));
                }
            }
        }
        if (ok) {
            cout << (ans == INT_MAX ? -1 : ans) << "\n";
        }
    }
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