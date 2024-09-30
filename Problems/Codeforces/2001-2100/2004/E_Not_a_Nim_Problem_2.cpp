#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

/*
    264ms
*/

vector<int> minp, primes;

void sieve(int n) {
    minp.resize(n + 1);
    primes.clear();

    for (int i = 2; i <= n; i++) {
        if (minp[i] == 0) {
            minp[i] = i;
            primes.push_back(i);
        }
        for (auto p : primes) {
            if (i * p > n) {
                break;
            }
            minp[i * p] = p;
            // 当我们发现 minp[i]（即 i 的当前最小质因数）等于当前的质数 p 时，就没有必要继续用更大的质数去乘以 i 并更新 minp 数组了
            if (p == minp[i]) {
                break;
            }
        }
    }
}

const int N = 10'000'000;

vector<int> sg;
auto init = []() {
    sieve(N);
    sg.resize(N);
    sg[0] = 0, sg[1] = 1, sg[2] = 0;
    for (int i = 1; i < primes.size(); ++i) {
        sg[primes[i]] = i + 1;
    }

    for (int i = 3; i <= N; ++i) {
        sg[i] = sg[minp[i]];
    }
    return 0;
}();

void solve() {
    int n;
    cin >> n;

    int xor_ = 0;
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        xor_ = xor_ ^ sg[val];
    }
    cout << (xor_ ? "Alice" : "Bob") << "\n";
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