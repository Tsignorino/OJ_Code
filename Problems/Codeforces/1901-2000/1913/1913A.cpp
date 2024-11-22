#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    string s;
    cin >> s;

    int n = s.size();
    int i = 1;
    while (s[i] - '0' == 0) {
        ++i;
    }

    if (i < n) {
        string s1 = s.substr(0, i), s2 = s.substr(i);
        if (stoi(s1) < stoi(s2)) {
            cout << s1 << " " << s2 << "\n";
            return;
        }
    }

    cout << "-1\n";
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
