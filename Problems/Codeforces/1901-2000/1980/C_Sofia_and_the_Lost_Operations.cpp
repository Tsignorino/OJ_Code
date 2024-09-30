#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n); // 原始数组
    vector<int> b(n); // 找到的数组
    for (int& v : a) {
        cin >> v;
    }

    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        if (b[i] != a[i]) {
            mp[b[i]]++;
        }
    }

    int m;
    cin >> m;
    vector<int> d(m);
    for (int& v : d) {
        cin >> v;
        mp[v]--;
    }

    for (auto& [_, c] : mp) {
        if (c > 0) {
            cout << "NO\n";
            return;
        }
    }
    cout << (find(b.begin(), b.end(), d.back()) != b.end() ? "YES" : "NO") << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
