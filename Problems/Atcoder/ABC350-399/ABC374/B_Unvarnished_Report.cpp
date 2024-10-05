#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    string s, t;
    cin >> s >> t;

    int n = s.size(), m = t.size();
    int i = 0, j = 0;
    while (i < n) {
        if (s[i] != t[j]) {
            cout << i + 1 << "\n";
            return;
        }
        i++, j++;
    }
    cout << (j == m ? 0 : j + 1) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}