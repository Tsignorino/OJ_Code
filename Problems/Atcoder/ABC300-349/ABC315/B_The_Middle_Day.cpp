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

    vector<int> a(n);
    for (int& v : a) {
        cin >> v;
    }

    int sum = accumulate(a.begin(), a.end(), 0);
    int need = (sum + 1) / 2;
    for (int i = 0; i < n; ++i) {
        if (need > a[i]) {
            need -= a[i];
        } else {
            cout << i + 1 << " " << need << "\n";
            break;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}