#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

/*
    608ms
*/

#define N 100'000'00
vector<int> isPrime(N + 1, 1);
vector<int> sg(N + 1);
int val = 1;
auto init = []() {
    isPrime[0] = isPrime[1] = 0;
    sg[1] = 1;
    for (int i = 2; i <= N; ++i) {
        if (!isPrime[i]) {
            continue;
        }
        for (int k = i; k <= N; k += i) {
            if (sg[k] == 0) {
                sg[k] = val;
            }
        }
        val++;
        for (long long j = i * 1ll * i; j <= N; j += i) {
            isPrime[j] = 0;
        }
    }

    for (int i = 0; i <= N; i += 2) { // 修正
        sg[i] = 0;
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