#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

/*
    字符比较  218ms
*/

void solve() {
    int n, q;
    cin >> n >> q;

    vector<string> vec(n);
    map<string, vector<int>> mp;
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
        mp[vec[i]].emplace_back(i);
    }

    while (q--) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        if (x > y) {
            swap(x, y);
        }

        int ans = INT_MAX / 2;
        for (char i : vec[x]) {
            for (char j : vec[y]) {
                if (i == j) {
                    ans = min(ans, y - x);
                    break;
                }

                string tmp = string(1, i) + j;
                ranges::sort(tmp);

                auto lo = ranges::lower_bound(mp[tmp], x);
                if (lo != mp[tmp].end() && (*lo) <= y) {
                    ans = min(ans, y - x);
                    break;
                }

                auto ro = ranges::upper_bound(mp[tmp], y);
                if (lo != mp[tmp].begin()) {
                    ans = min(ans, x + y - 2 * (*prev(lo)));
                }
                if (ro != mp[tmp].end()) {
                    ans = min(ans, 2 * (*ro) - x - y);
                }
            }
        }
        cout << (ans == INT_MAX / 2 ? -1 : ans) << "\n";
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