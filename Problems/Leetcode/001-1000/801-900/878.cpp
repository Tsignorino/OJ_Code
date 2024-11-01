#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
private:
    static constexpr int mod = 1e9 + 7;

public:
    int nthMagicalNumber(int n, int a, int b) {
        //* 二分 + 容斥
        // long long l = 0, r = min(a, b) * 1LL * n + 1;
        // long long ans = 0;
        // while (l + 1 < r) {
        //     long long mid = l + (r - l) / 2;

        //     if (mid / a + mid / b - mid / lcm(a, b) < n) {
        //         l = mid;
        //     } else {
        //         ans = r = mid;
        //     }
        // }
        // return ans % mod;

        //* 找规律
        int LCM = lcm(a, b);
        int cnt = LCM / a + LCM / b - 1;
        int ans = LCM * 1LL * (n / cnt) % mod;

        int k = n % cnt;
        if (k == 0) {
            return ans;
        }

        int delta1 = a, delta2 = b;
        for (int i = 0; i < k - 1; ++i) { // an operation was performed when return
            if (delta1 < delta2) {
                delta1 += a;
            } else {
                delta2 += b;
            }
        }

        return (ans + min(delta1, delta2) % mod) % mod;
    }
};