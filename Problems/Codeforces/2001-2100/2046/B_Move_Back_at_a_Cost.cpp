// Date: 2024-12-05  星期四

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> a, b;
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;

        while (!a.empty() && v < a.back()) {
            b.emplace_back(a.back() + 1);
            a.pop_back();
        }
        a.emplace_back(v);
    }

    ranges::sort(b);

    while (!b.empty() && a.back() > b[0]) { // '!a.empty()' can be ignored.
        b.emplace_back(a.back() + 1);
        a.pop_back();
    }

    ranges::sort(b);

    a.insert(a.end(), b.begin(), b.end());

    for (int& v : a) {
        cout << v << " ";
    }
    cout << "\n";
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