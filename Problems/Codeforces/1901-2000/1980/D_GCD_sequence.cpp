#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    vector<int> g(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        g[i] = gcd(vec[i], vec[i + 1]);
    }

    int less = 0;
    for (int i = 1; i < n - 1; ++i) {
        less += g[i] < g[i - 1];
    }

    int ans = 0;
    if (less == g[1] < g[0] || less == g[n - 2] < g[n - 3]) {
        ans = 1;
    }
    for (int i = 1; i < n - 1; ++i) {
        int tmp = less;
        tmp -= g[i] < g[i - 1];
        int val = gcd(vec[i - 1], vec[i + 1]);
        if (i > 1) {
            tmp -= g[i - 1] < g[i - 2];
            tmp += val < g[i - 2];
        }
        if (i < n - 2) {
            tmp -= g[i + 1] < g[i];
            tmp += val > g[i + 1];
        }
        if (tmp == 0) {
            ans = 1;
        }
    }

    cout << (ans == 1 ? "YES" : "NO") << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
