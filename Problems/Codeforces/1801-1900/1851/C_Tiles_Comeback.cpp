#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> vec(n);
    unordered_map<int, int> ump;
    for (int& val : vec) {
        cin >> val;
        ump[val]++;
    }

    if (ump[vec[0]] < k || ump[vec[n - 1]] < k) {
        cout << "NO\n";
        return;
    }
    if (vec[0] != vec[n - 1]) {
        int id, cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < n; ++i) {
            cnt1 += vec[i] == vec[0];
            if (cnt1 == k) {
                id = i;
                break;
            }
        }

        for (int i = n - 1; i > id; --i) {
            cnt2 += vec[i] == vec[n - 1];
        }

        if (cnt2 < k) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int count;
    cin >> count;
    while (count--) {
        solve();
    }

    return 0;
}
