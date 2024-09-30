#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

/*
    https://ac.nowcoder.com/acm/contest/88455/D
*/

#define N 300'0000
vector<int> isPrime(N + 1, 1);
vector<int> Primes;
auto init = []() {
    isPrime[0] = isPrime[1] = 0;
    for (int i = 2; i <= N; ++i) {
        if (!isPrime[i]) {
            continue;
        }
        for (long long j = i * 1ll * i; j <= N; j += i) {
            isPrime[j] = 0;
        }
        Primes.emplace_back(i);
    }
    return 0;
}();

void solve() {
    int n;
    cin >> n;

    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    set<int> s(vec.begin(), vec.end());
    for (int i : Primes) {
        if (!s.contains(i)) {
            cout << i << "\n";
            return;
        }
    }
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