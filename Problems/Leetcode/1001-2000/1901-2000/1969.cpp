#include <bits/stdc++.h>

using namespace std;

class Solution {
    const int mod = 1'000'000'007;

    long long pow(long long x, int p) { // x ^ (2 ^ p - 1)
        x %= mod;
        long long res = 1;
        while (p--) {
            res = res * x % mod;
            x = x * x % mod;
        }
        return res;
    }

public:
    int minNonZeroProduct(int p) {
        long long k = (1LL << p) - 1;
        return k % mod * pow(k - 1, p - 1) % mod;
    }
};