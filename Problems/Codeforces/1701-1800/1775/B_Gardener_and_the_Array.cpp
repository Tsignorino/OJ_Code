#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> vec(n);
    map<int, int> mp;
    for (vector<int>& v : vec) {
        int k;
        cin >> k;
        v.resize(k);
        for (int& val : v) {
            cin >> val;
            mp[val]++;
        }
    }

    for (vector<int>& v : vec) {
        bool flag = false;
        for (int& val : v) {
            if (mp[val] == 1) {
                flag = true;
                break;
            }
        }
        if (flag) {
            continue;
        }

        cout << "Yes\n";
        return;
    }
    cout << "No\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(20);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
