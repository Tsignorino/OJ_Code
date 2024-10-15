#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int mod = 1e9 + 7;

void solve() {
    string s, t;
    cin >> s >> t;

    int cnt = 0;
    for (char& ch : s) {
        if (cnt < 3 && toupper(ch) == t[cnt]) {
            cnt++;
        }
    }
    cout << (cnt == 3 || cnt == 2 && t[2] == 'X' ? "Yes" : "No") << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
