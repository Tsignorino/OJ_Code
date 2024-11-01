#include <bits/stdc++.h>

using namespace std;
using ll = long long;

uint64_t MOD = mt19937_64 {random_device()()}();

void solve() {
    int n;
    cin >> n;

    vector<uint64_t> vec(n);
    map<uint64_t, int> mp;
    for (auto& v : vec) {
        string s;
        cin >> s;

        for (char ch : s) {
            v = ((__uint128_t) v * 10 + ch - '0') % MOD;
        }
        mp[v]++;
    }

    int ans = 0;
    for (auto& i : vec) {
        for (auto& j : vec) {
            uint64_t k = (__uint128_t) i * j % MOD;
            if (mp.contains(k)) {
                ans += mp[k];
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}