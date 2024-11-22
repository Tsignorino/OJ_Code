#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    //* A 00, B 01, C 10, ? 11
    char ch;
    for (int i = 0; i < 3; ++i) {
        int ans = 0;
        for (int j = 0; j < 3; ++j) {
            cin >> ch;
            ans += ch == '?' ? 3 : ch - 'A';
        }
        if (ans != 3) {
            cout << (char) (6 - ans + 'A') << "\n";
        }
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
