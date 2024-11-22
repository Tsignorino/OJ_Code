#include <bits/stdc++.h>

using namespace std;
using ll = long long;

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
