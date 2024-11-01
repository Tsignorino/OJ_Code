#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    map<int, int> map;
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        map[val]++;
    }

    // 只要有一个值出现奇数次即可
    for (auto& [_, c] : map) {
        if (c % 2 == 1) {
            cout << "YES\n";
            return;
        }
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