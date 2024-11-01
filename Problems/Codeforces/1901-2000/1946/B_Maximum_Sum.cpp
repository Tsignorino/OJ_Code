#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

long long quickPow(long long a, long long b, int p) {
    long long ans = 1;
    a = (a % p + p) % p;

    for (; b; b >>= 1) {
        if (b & 1) {
            ans = a * ans % p;
        }

        a = a * a % p;
    }

    return ans;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> vec(n);
    ll maxV = 0, tmp = 0, sum = 0;
    for (int& v : vec) {
        cin >> v;

        sum += v;
        tmp += v;
        tmp = max(tmp, 0ll);
        maxV = max(maxV, tmp);
    }

    cout << (maxV % mod * quickPow(2, k, mod) % mod + (sum % mod + mod) % mod - maxV % mod + mod) % mod << "\n";
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
