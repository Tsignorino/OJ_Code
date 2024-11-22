#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    string s;
    int n;
    cin >> n >> s;

    string res = "";
    while (!s.empty()) {
        int x;
        if (s.back() == 'a' || s.back() == 'e') {
            x = 2;
        } else {
            x = 3;
        }

        while (x--) {
            res += s.back();
            s.pop_back();
        }

        res += '.';
    }

    res.pop_back();
    reverse(res.begin(), res.end());

    cout << res << '\n';
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