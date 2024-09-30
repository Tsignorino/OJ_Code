#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;

    vector<int> res;
    vector<int> isPrime(n + 1, 1);
    isPrime[0] = isPrime[1] = 0;
    for (int i = 2; i <= n; ++i) {
        if (!isPrime[i]) {
            continue;
        }
        for (int v = i; v <= n; v *= i) {
            res.emplace_back(v);
        }

        for (int j = i * i; j <= n; j += i) {
            isPrime[j] = 0;
        }
    }

    cout << res.size() << "\n";
    for (int& v : res) {
        cout << v << " ";
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);

    solve();

    return 0;
}
