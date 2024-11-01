#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define mod 1e9 + 7

void solve() {
    int n, m;
    cin >> n >> m;

    vector<string> vec(n);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }

    string s("vika");
    int k = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (vec[j][i] == s[k]) {
                k++;
                break;
            }
        }
    }

    cout << (k == 4 ? "YES" : "NO") << "\n";
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
