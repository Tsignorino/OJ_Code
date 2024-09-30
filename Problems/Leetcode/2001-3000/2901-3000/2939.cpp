/**
 * (最大异或乘积) https://leetcode.cn/problems/maximum-xor-product/description/
 */

// 给你三个整数 a ，b 和 n ，请你返回(a XOR x)* (b XOR x) 的 最大值 且 x 需要满足 0 <= x < 2n。
// 由于答案可能会很大，返回它对 1e9 + 7 取余 后的结果。

#include <algorithm>
#include <iostream>


using namespace std;

/*
位运算：

    （周赛中想到的）对于同一个比特位，如果一个是 0，另一个是 1，则无论 x 取 0 还是 1，最后异或的结果总是 一个是 0，另一个是 1。

    >> 把同为 0 的比特位改为 1 之后（相当于理想的异或结果中的一种情况），1 的总个数不变。
    >> 异或结果之和为定值！

    >> 之后需要解决的问题：
        如何让两个数异或之后尽可能接近？
        1. 考虑 一个0，另一个为1 的比特位，异或相当于 两数交换或者不交换同一比特位的数，
            最后所有异或可能的结果都可以通过若干次交换变为 全1 和全0。

        2. 分配 1 的方案：最高位的 1 给一个数，剩下的 1 位 给另一个数

        3. 考虑 0 <= x < 2**n 的限制：
            两个数与 x 的异或只能影响 低 n 位，对高位进行讨论：
                > 高位 a == b：方案不变
                > 高位 a > b：把低位 1 全给 b (为了便于编写代码，可以直接交换 a 和 b 的值)

    · 注意事项：
        > 左移运算中的 1 和 API，要改成 long long 形式
        > 乘积溢出，最后结果要先取余
*/

class Solution {
public:
    const long long mod = 1e9 + 7;

public:
    int maximumXorProduct(long long a, long long b, int n) {
        if (a < b) {
            swap(a, b); // 保证 a >= b
        }

        long long mask = (1LL << n) - 1; // 低 n 位为 1，高位为 0

        // 保留高位，低位置0
        long long ax = a & ~mask;
        long long bx = b & ~mask;

        // 截断高位，取低位
        a &= mask;
        b &= mask;

        long long left = a ^ b; // 一个是 0，另一个是 1 的比特位
        long long one = left ^ mask; // 两个数同为 0 或 1 的比特位
        // 把不参加分配的比特位添加到异或结果中
        ax |= one;
        bx |= one;

        // 低位分配
        if (left > 0 && ax == bx) {
            long long high_bit = 1LL << (63 - __builtin_clzll(left));
            ax |= high_bit; // 把最高位给 ax
            left ^= high_bit; // 从 left 中去掉最高比特位
        }
        bx |= left;

        return (ax % mod) * (bx % mod) % mod;
    }
};

int main() {
    int a = 12, b = 5, n = 4;

    Solution s;
    cout << s.maximumXorProduct(a, b, n);

    return 0;
}