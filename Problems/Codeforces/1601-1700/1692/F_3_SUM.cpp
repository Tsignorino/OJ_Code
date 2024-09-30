#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> cnt(10);
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;
        cnt[v % 10]++;
    }

    for (int i = 0; i < 10; ++i) {
        if (cnt[i] == 0) {
            continue;
        }
        for (int j = 0; j < 10; ++j) {
            if (i == j && cnt[j] <= 1 || i != j && cnt[j] == 0) {
                continue;
            }

            int k = (23 - i - j) % 10;
            if (cnt[k] > 2 || (i == k && j != k || i != k && j == k) && cnt[k] > 1 || (i != k && j != k) && cnt[k] > 0) {
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
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
