// Date: 2024-12-10  星期二

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

void solve() {
    string s;
    cin >> s;

    vector<int> a(26);
    for (char ch : s) {
        a[ch - 'a'] ^= 1;
    }

    int cnt = 0;
    for (int i = 0; i < 26; ++i) {
        cnt += a[i];
    }
    cout << (cnt == 0 || cnt % 2 ? "First" : "Second") << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}