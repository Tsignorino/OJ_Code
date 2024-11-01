#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int mod = 1e9 + 7;

void solve() {
    string s, t;
    cin >> s >> t;

    for (int i = 0, j = 0; i < s.size(); ++j) {
        if (s[i] == t[j]) {
            ++i;
            cout << j + 1 << " ";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
