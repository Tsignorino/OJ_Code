#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

#define N 1'000'000

vector<int> minp(N + 1);
auto init = []() {
    vector<int> primes;
    for (int i = 2; i <= N; ++i) {
        if (minp[i] == 0) {
            minp[i] = i;
            primes.emplace_back(i);
        }

        for (int& p : primes) {
            if (i * p > N) {
                break;
            }
            minp[i * p] = p;
            if (p == minp[i]) {
                break;
            }
        }
    }
    return 0;
}();

void solve() {
    int n, m;
    cin >> n >> m;

    cout << (n == 1 || minp[n] > m ? "YES" : "NO") << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int count;
    cin >> count;
    while (count--) {
        solve();
    }

    return 0;
}
