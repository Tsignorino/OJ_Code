// Date: 2024-12-11  星期三

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    map<int, int> mp;
    map<int, int> mp1;
    map<int, int> mp2;
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;
        mp[v]++, mp1[v]++;
    }
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;
        mp[v]++, mp2[v]++;
    }

    int ans = 0;
    for (auto& [_, c] : mp) {
        ans += c - 1;
    }
    ans = (ans + 1) / 2;
    for (auto mp : {mp1, mp2}) {
        int res = 0;
        for (auto& [_, c] : mp) {
            res += c - 1;
        }
        ans = max(ans, res);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}