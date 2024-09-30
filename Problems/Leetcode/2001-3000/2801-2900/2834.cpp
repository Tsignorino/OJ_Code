#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
    static constexpr int mod = 1e9 + 7;

public:
    int minimumPossibleSum(int n, int target) {
        // int t = target / 2;
        // if (n <= t) {
        //     return (1 + n) * 1LL * n / 2 % mod;
        // }

        // ll ans = (1 + t) * 1LL * t / 2 % mod;
        // ans = (ans + (2LL * target + n - t - 1) % mod * (n - t) / 2) % mod;
        // return ans;

        ll m = min(target / 2, n);
        return (m * (m + 1) + (n - m - 1 + target * 2) * (n - m)) / 2 % mod;
    }
};