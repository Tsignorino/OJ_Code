#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    string words[3][n];
    unordered_map<string, int> ump;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> words[i][j];
            ump[words[i][j]]++;
        }
    }

    for (int i = 0; i < 3; ++i) {
        int total = 0;
        for (int j = 0; j < n; ++j) {
            if (ump[words[i][j]] == 1) {
                total += 3;
            } else if (ump[words[i][j]] == 2) {
                total += 1;
            }
        }
        cout << total << " ";
    }

    cout << "\n";
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
