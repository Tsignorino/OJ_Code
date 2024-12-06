// Date: 2024-12-06  星期五

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

void solve() {
    string s;
    cin >> s;

    int n = s.size();
    for (int i = 0; i < n; ++i) {
        int k = i;
        for (int j = i; j < n && j < i + 10; ++j) { // 每个数移动次数有限
            if (s[j] - j > s[k] - k) {
                k = j;
            }
        }
        for (; k > i; --k) {
            swap(s[k - 1], --s[k]);
        }
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