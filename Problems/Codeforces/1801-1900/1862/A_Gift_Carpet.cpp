#include <bits/stdc++.h>

using namespace std;
using ll = long long;

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
