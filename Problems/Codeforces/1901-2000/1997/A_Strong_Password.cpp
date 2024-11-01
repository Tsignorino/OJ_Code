#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    string s;
    cin >> s;

    int ok = 1;
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] == s[i - 1]) {
            ok = 0;
            s.insert(s.begin() + i, s[i] == 'a' ? 'b' : s[i] - 1);
            break;
        }
    }
    if (ok) {
        s.push_back(s.back() == 'a' ? 'b' : s.back() - 1);
    }
    cout << s << "\n";
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