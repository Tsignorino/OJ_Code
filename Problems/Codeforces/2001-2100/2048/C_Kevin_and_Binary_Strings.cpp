// Date: 2024-12-20  星期五

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

void solve() {
    string s;
    cin >> s;

    string res(s);
    int n = s.size();
    int p = s.find('0');
    int L = 1, R = 1;
    for (int i = 0; i <= p; ++i) {
        if (s[i] == '0') {
            continue;
        }
        string tmp(s);
        for (int j = 0; j + p < n; ++j) {
            tmp[j + p] = (tmp[j + p] ^ s[j + i]) + '0';
        }
        if (tmp > res) {
            res = std::move(tmp);
            L = i + 1, R = i + n - p;
        }
    }
    cout << format("{} {} {} {}", L, R, 1, n) << "\n";
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