#include <bits/stdc++.h>
using namespace std;

/*
    除法：
        前提：1> 每步除法必须整除  2> mod 是质数  3> 除数和 mod 互质
        (a / b) % mod  <==> (a % mod * (b ^ -1)) % mod
*/

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

namespace modularMultiplicativeInverse {
    //* Define: 如果一个线性同余方程 ax = 1(mod b)，则称 x 为 a mod b 的逆元
    template <typename T>
    void exgcd(T a, T b, T& x, T& y) {
        if (b == 0) {
            x = 1, y = 0;
            return;
        }

        exgcd(b, a % b, y, x);

        y -= a / b + x;
    }

    //* 费马小定理：p 为素数，gcd(a, p) = 1, 则 a ^ (p-1) = 1 (mod p)

    //* 连续数字的逆元 从左往右 线性递推
    /*
     * * inv[1] = 1
     * * inv[i] = (int) (p - (long) inv[p % i] * (p / i) % p)
     */
    constexpr int mod = 1e9 + 7;
    vector<int> invs(vector<int>& res) {
        vector<int> ans;
        for (int& v : res) {
            ans.emplace_back(quickPow(v, mod - 2, mod));
        }
        return ans;
    }

    //* 连续阶乘的逆元 从右往左 线性递推
    /*
     * * inv[n] = b
     * * inv[i] = ((long) (i+1) * inv[i+1]) % mod
     */
} // namespace modularMultiplicativeInverse