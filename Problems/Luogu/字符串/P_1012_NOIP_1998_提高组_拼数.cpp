// Date: 2024-11-29  星期五

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;

    vector<string> vec(n);
    for (string& v : vec) {
        cin >> v;
    }

    // 拼出最大的字符串
    ranges::sort(vec, [&](string& a, string& b) { return a + b > b + a; });

    for (string& v : vec) {
        cout << v;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}