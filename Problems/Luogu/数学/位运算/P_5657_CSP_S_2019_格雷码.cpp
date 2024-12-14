// Date: 2024-12-14  星期六

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

// 考虑答案的每一位，第 i 位即 k ^ (k/2) 的第 i 位

void solve() {
    int n;
    unsigned long long k;
    cin >> n >> k;

    k ^= k >> 1;
    while (n--) {
        cout << (k >> n & 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}