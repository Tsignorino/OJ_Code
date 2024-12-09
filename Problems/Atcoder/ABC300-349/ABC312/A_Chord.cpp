// Date: 2024-12-09  星期一

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

set<string> S {"ACE", "BDF", "CEG", "DFA", "EGB", "FAC", "GBD"};

void solve() {
    string s;
    cin >> s;

    cout << (S.contains(s) ? "Yes" : "No") << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}