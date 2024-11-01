#include <bits/stdc++.h>

using namespace std;

long long quickPow(long long a, long long b) {
    long long res = 1;
    for (; b; b >>= 1) {
        if (b & 1) {
            res = res * a;
        }
        a = a * a;
    }
    return res;
}

class Solution {
    static constexpr int MOD = 1e9 + 7;

public:
    int numberOfWays(int n, int x) {
        vector<long long> f(n + 1);
        f[0] = 1;
        for (int i = 1;; ++i) {
            long long tmp = quickPow(i, x);
            if (tmp > n) {
                break;
            }
            for (int s = n; s >= tmp; --s) {
                f[s] += f[s - tmp];
            }
        }
        return f[n] % MOD;
    }
};

int main() {
    Solution sol;

    return 0;
}